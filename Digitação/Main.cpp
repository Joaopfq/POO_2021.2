#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <functional>

struct Pincel
{
	sf::Font font;
	sf::Text text;
	sf::RenderWindow& window;

	Pincel(sf::RenderWindow& window) :
		window(window)
	{
		if (!font.loadFromFile("cartoon.ttf"))
			std::cout << "Font not loaded" << std::endl;
		text.setFont(font);
	}

	void write(std::string str, int x, int y, int size, sf::Color color)
	{
		text.setString(str);
		text.setCharacterSize(size);
		text.setPosition(x, y);
		text.setFillColor(color);
		window.draw(text);
	}
};

struct Bubble
{
	static const int radius { 10 };
	int x;
	int y;
	char letter;
	int speed;
	bool alive { true };

	Bubble(int x, int y, char letter, int speed)
	{
		this->x = x;
		this->y = y;
		this->letter = letter;
		this->speed = speed;
	}

	void update()
	{
		y += speed;
	}

	void draw(sf::RenderWindow& window)
	{

		sf::CircleShape bubble(Bubble::radius);
		bubble.setPosition(x, y);
		bubble.setFillColor(sf::Color::White);
		window.draw(bubble);

		static Pincel pincel(window);
		pincel.write(std::string(1, letter), x + 0.7 * Bubble::radius, y, Bubble::radius * 1.7, sf::Color::Black);
	}
};

struct Board{
	sf::RenderWindow& window;
	std::vector <Bubble> bubbles;
	Pincel pincel;
	int hits{ 0 };
	int misses{ 0 };

	Board(sf::RenderWindow& window) : window{window}, pincel{window} {
		bubbles.push_back(Bubble(100, 100, 'A', 1));
		bubbles.push_back(Bubble(200, 100, 'B', 1));
		bubbles.push_back(Bubble(300, 100, 'C', 1));
	}

	void update() {
		if(this->check_new_bubble())
			this->add_new_bubble();

		for(Bubble& bubble: bubbles){
			bubble.update();
		}
		this->mark_outside_bubbles();
		this->remove_dead_bubbles();
	}

	void remove_dead_bubbles() {
		std::vector<Bubble> vivas;
		for	(Bubble& bubble : bubbles) {
			if(bubble.alive) {
				vivas.push_back(bubble);
			}
		}
		this->bubbles = vivas;
	}

	void mark_outside_bubbles() {
		for(Bubble& bubble : bubbles) {
			if(bubble.y + 2 * Bubble::radius > (int) this->window.getSize().y) {
				if(bubble.alive){
					bubble.alive = false;
					this->misses ++;
				}
			}
		}
	}

	void mark_by_hit(char letter) {
		for(Bubble& bubble : bubbles){
			if(bubble.letter == letter) {
				bubble.alive = false;
				this->hits++;
				break;
			}
		}
	}

	bool check_new_bubble() {
		static const int new_bubble_timeout{30};
		static int new_bubble_timer{ 0 };

		new_bubble_timer--;
		if(new_bubble_timer <= 0) {
			new_bubble_timer = new_bubble_timeout;
			return true;
		}
		return false;
	}

	void add_new_bubble() {
		int x = rand() % ((int) this->window.getSize().x - 2 * Bubble::radius);
		int y = - 2 * Bubble::radius;
		int speed = rand() % 5 + 1;
		char letter = rand() % 26 + 'A';
		bubbles.push_back(Bubble(x, y, letter, speed));
	}

	void draw() {
		pincel.write("Hits: " + std::to_string(this->hits) + " Misses: " + std::to_string(this->misses), 10, 10, 20, sf::Color::White);
		pincel.write("Size " + std::to_string(this->bubbles.size()), 10, 30, 20, sf::Color::White);
		for(Bubble& bubble : bubbles){
			bubble.draw(window);
		}
	}
};

struct Game
{
	sf::RenderWindow window;
	Board board;

	std::function<void()> on_uptade;

	Game() :
		window(sf::VideoMode(800, 600), "Bubbles"), board(window) {
		this->on_uptade = [&]() {
			this->gameplay();
		};
		window.setFramerateLimit(60);
	}

	void process_events()
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			} else if(event.type == sf::Event::TextEntered) {
			char code = static_cast<char>(event.text.unicode);
			code = toupper(code);
			board.mark_by_hit(code);
			}
		}
	}

	void gameplay()
	{
		board.update();
		window.clear(sf::Color::Black);
		board.draw();
		window.display();
		if(board.misses > 10) {
			this -> on_uptade = [&]() {
				this->gameover();
			};
		}
	}

	void gameover(){
		static Pincel pincel(window);
		window.clear(sf::Color::Red);
		pincel.write("Game Over", 250, 250, 50, sf::Color::Black);
		window.display();
	}

	void main_loop()
	{
		while (window.isOpen())
		{
			process_events();
			on_uptade();
		}
	}
};

int main()
{
	Game game;
	game.main_loop();
	return 0;
}