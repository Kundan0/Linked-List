#include<iostream>
#include<SFML/Graphics.hpp>


struct Node
{
	sf::RectangleShape rect;
	sf::Text text;
	
	int data;
	Node* next;
	Node* prev;
};
Node *start=NULL;
sf::Font font;
void update(sf::RenderWindow*,Node*);
void updateOrigin(Node*);
Node* newNode(int data)
{
	Node* newnode = new Node;
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->rect.setSize(sf::Vector2f(70, 20));
	//newnode->rect.setFillColor(sf::Color::White);
	return newnode;
	
	
}
void insertAfter(sf::RenderWindow* wind, int position,int data)
{
	
	
	Node* newnode = newNode(data);
	if (start== NULL) 
	{
		std::cout << "i am creating start" << std::endl;
		//std::cout << "newnode key" << newnode->data;
		start=newnode;
	
		//std::cout << start->data;
		start->rect.setOrigin(sf::Vector2f(-100, -400));
		
		update(wind,newnode);
		return;
	}
	else
	{
		
		if (position != 0) 
		{
			Node* temp;
			temp = start;
			int count = 0;
			while (count < (position-1))
			{
				
				temp = temp->next;
				count++;
			}

			newnode->next = temp->next;
			newnode->prev = temp;
			if (temp->next != NULL) {
				temp->next->prev = newnode;
			}
			temp->next = newnode;
			
			std::cout << "position=1" << std::endl;
			updateOrigin(newnode);
			update(wind,newnode);
		}
		if (position == 0)
		{
			std::cout << "position=0" << std::endl;
			
			newnode->next = start;
			start->prev = newnode;
			start = newnode;
			
			updateOrigin(newnode);
			update(wind,newnode);
		}
		//std::cout << "I am checking in else statement of insertnow i am calling update origin" << std::endl;
		return;
	}
	
	
	
	

}
void display()
{
	Node* temp;
	temp = start;
	while (temp != NULL)
	{
		std::cout << temp->rect.getOrigin().x<<"   "<< temp->rect.getOrigin().y <<"         "<<temp->data<<std::endl;
		temp = temp->next;
	}
	std::cout << "................"<<std::endl;
}
void updateOrigin(Node* t)
{
	
	std::cout << "updating origins" << std::endl;
	Node* p = t->prev;
	std::cout << t->rect.getOrigin().y << std::endl;
	if (p != NULL) 
	{
		
		while (t!= NULL)
		{

			p = t->prev;
			sf::Vector2f pos = p->rect.getOrigin();
			
			t->rect.setOrigin(sf::Vector2f(pos.x-100 , pos.y));
			t = t->next;
		}
		
		return;
	}
	else
	{

		
		
		t->rect.setOrigin(sf::Vector2f(-100, -400));
		t = t->next;
		while (t!= NULL) 
		{
			p = t->prev;
			sf::Vector2f pos = p->rect.getOrigin();

			t->rect.setOrigin(sf::Vector2f(pos.x - 100, pos.y));
			t = t->next;
			
		}
	}
}

void update(sf::RenderWindow* window,Node* n)
{
if (n != NULL) {
		
		
		Node* temp;
		temp = start;
		
		while (temp != NULL) {

			
			if (temp == start)
				temp->rect.setFillColor(sf::Color::Green);
			else if (temp == n)
				temp->rect.setFillColor(sf::Color::Red);
			else temp->rect.setFillColor(sf::Color::Blue);
			
			window->draw(temp->rect);
			temp = temp->next;
		}
		window->display();
		
		
	}
	
	
	
}
void backgroun(sf::RenderWindow* window)
{
	sf::RectangleShape background;
	background.setOrigin(sf::Vector2f(-650, -350));
		background.setSize(sf::Vector2f(300, 100));
		while (window->isOpen())
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				window->clear(sf::Color::Black);
				return;
			}
			window->draw(background);
			window->display();
        }
}
void options(sf::RenderWindow* window)
{
	sf::Texture text;
	text.loadFromFile("S.png");
	sf::Sprite sprite;
	sprite.setTexture(text);
	
	
	sprite.setOrigin(sf::Vector2f(-400, -200));
	window->draw(sprite);
	window->display();

}
void Createwindow()
{
	
	sf::RenderWindow window(sf::VideoMode(1600, 800), "Linked List");
	backgroun(&window);
	options(&window);
	std::cout << "i have returned from background" << std::endl;
	
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


	}
	
}
int main()
{
	
	Createwindow();
}
