#include "Main.hpp"
#include "Platform/Platform.hpp"
#include <SFML/Graphics.hpp>

void setSize(sf::Sprite& sprite, int width, int height)
{
	auto dim = sprite.getLocalBounds();
	sprite.setScale((float)width / dim.width, (float)height / dim.height);
}

struct Entity
{
	int x { 0 };
	int y { 0 };
	int step { 0 };
	sf::Sprite sprite;

	Entity(int x, int y, int step, sf::Texture& texture) :
		x { x },
		y { y },
		step { step },
		sprite(texture)
	{
	}

	void draw(sf::RenderWindow& window)
	{
		this->sprite.setPosition(x * step, y * step);
		setSize(this->sprite, step, step);
		window.draw(this->sprite);
	}
};

void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys)
{
	if (key == move_keys[0])
		entity.x--;
	else if (key == move_keys[1])
		entity.y--;
	else if (key == move_keys[2])
		entity.x++;
	else if (key == move_keys[3])
		entity.y++;
}

struct Board{
	int nc {};
	int nl {};
	int step {};
	sf::Sprite sprite;
	sf::RectangleShape rect;
	Board(int nc, int nl, int step, sf::Texture& texture) {
		this->nc = nc;
		this->nl = nl;
		this->step = step;
		this->sprite.setTexture(texture);
		setSize(this->sprite, nc * step, nl *step);
		this->sprite.setPosition(0, 0);

		this->rect.setSize(sf::Vector2f(step, step));
		this->rect.setFillColor(sf::Color::Transparent);
		this->rect.setOutlineColor(sf::Color::Black);
		this->rect.setOutlineThickness(1);

	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(this->sprite);
		for(int i = 0; i < nc; i++) {
			for(int j = 0; j < nl; j++) {
				rect.setPosition(i * step, j * step);
				window.draw(rect);
			}
		}
	}
};


int main()
{

	sf::Texture sif_tex;
	sif_tex.loadFromFile("sif2.gif");
	sf::Texture sun_tex;
	sun_tex.loadFromFile("Sun.gif");
	sf::Texture bossRoom_tex;
	bossRoom_tex.loadFromFile("bossRoom.png");

	const int STEP{100};

	Entity sif(1, 2, STEP, sif_tex);
	Entity sun(3, 3, STEP, sun_tex);
	Board bossRoom(7, 5, STEP, bossRoom_tex);

	sf::RenderWindow window(sf::VideoMode(bossRoom.nc * STEP, bossRoom.nl * STEP), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				moveEntity(event.key.code, sif, { sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down });
				moveEntity(event.key.code, sun, { sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S });
			}
		}

		window.clear();
		bossRoom.draw(window);
		sif.draw(window);
		sun.draw(window);
		window.display();
	}

	return 0;
}
