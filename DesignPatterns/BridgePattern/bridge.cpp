/*
 * Example of `bridge' design pattern
 * Copyright (C) 2011 Radek Pazdera

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>

/* Implemented interface. */
class AbstractInterface
{
    public:
        virtual void someFunctionality() = 0;
};

/* Interface for internal implementation that Bridge uses. */
class ImplementationInterface
{
    public:
        virtual void anotherFunctionality() = 0;
};

/* The Bridge */ 
class Bridge : public AbstractInterface
{
    protected:
        ImplementationInterface* implementation;
    
    public:
        Bridge(ImplementationInterface* backend)
        {
            implementation = backend;
        }
};

/* Different special cases of the interface. */

class UseCase1 : public Bridge
{
    public:
        UseCase1(ImplementationInterface* backend)
          : Bridge(backend)
        {}

        void someFunctionality()
        {
            std::cout << "UseCase1 on ";
            implementation->anotherFunctionality();
        }
};

class UseCase2 : public Bridge
{
    public:
        UseCase2(ImplementationInterface* backend)
          : Bridge(backend)
        {}

        void someFunctionality()
        {
            std::cout << "UseCase2 on ";
            implementation->anotherFunctionality();
        }
};

/* Different background implementations. */

class Windows1 : public ImplementationInterface
{
    public:
        void anotherFunctionality()
        {
            std::cout << "Windows :-!" << std::endl;
        }
};

class Linux : public ImplementationInterface
{
    public:
        void anotherFunctionality()
        {
            std::cout << "Linux! :-)" << std::endl;
        }
};

int main44()
{
    AbstractInterface *useCase = 0;
    ImplementationInterface *osWindows = new Windows1;
    ImplementationInterface *osLinux = new Linux;


    /* First case */
    useCase = new UseCase1(osWindows);
    useCase->someFunctionality();

    useCase = new UseCase1(osLinux);
    useCase->someFunctionality();

    /* Second case */
    useCase = new UseCase2(osWindows);
    useCase->someFunctionality();

    useCase = new UseCase2(osLinux);
    useCase->someFunctionality();

    return 0;
}
