#include "CustomException.h"



CustomException::CustomException(const string file, int line, int status): 
	m_file(file), m_line(line), m_status(status)
{
}

CustomException::CustomException(const  string file, int line, int status, const  string message) :
	m_file(file), m_line(line), m_status(status), m_message(message)
{

}

CustomException::~CustomException()
{
}

const string CustomException::getMessage()
{
	return m_message;
}

const string CustomException::getFile()
{
	return m_file;
}

int CustomException::getLine()
{
	return m_line;
}

int CustomException::getStatus()
{
	return m_status;
}
