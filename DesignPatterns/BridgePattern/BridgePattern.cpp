#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <iostream>

using namespace std;

// 1. Message - Abstraction Class.
// 2. SystemMessage & UserMessage- Redefined Abstraction Classes.
// 3. IMessageSender- Bridge Interface.
// 4. EmailSender, WebServiceSender & MSMQ Sender- ConcreteImplementation class which implements the IMessageSender interface.

//// Abstarct Interface
///* Implemented interface. */
//public class IMessage
//{
//public:
//	virtual void sendMessage() = 0;
//	virtual string getMessage() = 0;
//};

/* Interface for internal implementation that Bridge uses. */
public class ImplementationIMessage
{
public:
	virtual void send(string msg) = 0;
	virtual string Get() = 0;
};

/* The Bridge */
public class Message /*: public IMessage*/
{
protected:
	ImplementationIMessage* implementation;

public:
	Message(ImplementationIMessage* backend)
	{
		implementation = backend;
	}
		virtual void sendMessage() = 0;
		virtual string getMessage() = 0;

};

public class SystemMessage :public Message
{

public:
	SystemMessage(ImplementationIMessage * implMessage) :Message(implMessage)
	{}

	void sendMessage()
	{
		implementation->send("SystemMessage");
	}
	string getMessage() { return implementation->Get(); };
};

public class UserMessage :public Message
{

public:
	UserMessage(ImplementationIMessage * implMessage) :Message(implMessage)
	{}

	void sendMessage()
	{
		implementation->send("UserMessage");
	}

	string getMessage() { return implementation->Get(); };
};


public class EmailSender :public ImplementationIMessage
{
public:
	void send(string msg)
	{
		cout << "Sending Email: " << msg.c_str() << endl;
	}
	string Get() { return "EmailSender"; };
};

public class WebServiceSender : public ImplementationIMessage
{
public:
	void send(string msg)
	{
		cout << "Sending WebServiceSender: " << msg.c_str() << endl;
	}
	string Get() { return "WebServiceSender"; };
};


int main()
{
	cout << "Main started"<<endl;
	Message * message = 0;
	ImplementationIMessage  * msgEmail = new EmailSender;
	ImplementationIMessage * msgWebServices = new WebServiceSender;


	message = new UserMessage(msgEmail);
	message->sendMessage();
	cout<<message->getMessage().c_str()<<endl;
	message = new UserMessage(msgWebServices);
	message->sendMessage();
	cout << message->getMessage().c_str() << endl;

	message = new SystemMessage(msgEmail);
	message->sendMessage();
	cout << message->getMessage().c_str() << endl;
	message = new SystemMessage(msgWebServices);
	message->sendMessage();
	cout << message->getMessage().c_str() << endl;

	return 0;
}