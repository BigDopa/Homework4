#ifndef POST_H
#define POST_H
#include <iostream>
#include <vector>
class post
{
public:
	//default constructor
	post();
	//primary constructor
	post(int i, std::string m, int a, int l);
	//a virtual method that outputs the message, as well as number of people that liked it  
	virtual std::string displayPost();
	//accessors
	int getID() const;
	std::string getMESSAGE() const;
	int getAUTHOR() const;
	int getLIKES() const;
private:
	//timestamp of ID
	int id_;
	//holds message of post
	std::string message_;
	//ID of author of post
	int author_;
	//Number of likes
	int likes_;
};

class directmessage: public post
{
public:
	//default constructor
	DirectMessage();
	//primary constructor
	DirectMessage(int i, std::string m, int a, int l, int r);
	//a method that returns the direct message
	std::string displayPost();
	//accessors
	int getRECIPIENT() const;
private:
	//ID of reciever of message
	int recipient_;

};
#endif
