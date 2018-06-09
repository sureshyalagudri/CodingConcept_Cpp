#include "Singleton.h"

Singleton * Singleton::m_instance = NULL;

Singleton::Singleton()
{
}
Singleton::~Singleton()
{
}
Singleton * Singleton::GetInstance()
{
	if (!m_instance)
		m_instance = new Singleton();

	return m_instance;
}

int Singleton::add(int a, int b) { return a + b; }

void Singleton::Delete()
{
	if (!m_instance)
		delete m_instance;
}