#include <iostream>
#include <cstdio>
using namespace std;

class Time
{
public:
	int hours, minutes, seconds;
	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int hours, int minutes, int seconds) {
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	Time(const Time& obj) {
		hours = obj.hours;
		minutes = obj.minutes;
		seconds = obj.seconds;
	}

	void setData(int hours, int minutes, int seconds) {
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	Time operator+(Time& obj) {
		Time newTimeObj;
		int timeSum, timeCarry;

		timeSum = seconds + obj.seconds;
		if (timeSum > 60)
		{
			timeCarry = 1;
			timeSum = timeSum - 60;
			newTimeObj.seconds = timeSum;
		} else {
			timeCarry = 0;
			newTimeObj.seconds = timeSum;
		}

		// Here we have to consider the timeCarry from the seconds
		timeSum = minutes + obj.minutes + timeCarry;
		if (timeSum > 60)
		{
			timeCarry = 1;
			timeSum = timeSum - 60;
			newTimeObj.minutes = timeSum;
		} else {
			timeCarry = 0;
			newTimeObj.minutes = timeSum;
		}

		// At last the hour
		newTimeObj.hours = hours + obj.hours + timeCarry;

		return newTimeObj;
	}

	// prefix addition overloading
	Time operator++() {
		int timeSum, timeCarry;

		timeSum = seconds + 1;
		if (timeSum > 60)
		{
			timeCarry = 1;
			timeSum = timeSum - 60;
			seconds = timeSum;
		} else {
			timeCarry = 0;
			seconds = timeSum;
		}

		// Here we have to consider the timeCarry from the seconds
		timeSum = minutes + timeCarry;
		if (timeSum > 60)
		{
			timeCarry = 1;
			timeSum = timeSum - 60;
			minutes = timeSum;
		} else {
			timeCarry = 0;
			minutes = timeSum;
		}

		// At last the hour
		hours = hours + timeCarry;

		return (*this);
	}

	// For post overator
	Time operator++(int)
	{
		Time temp = (*this);
		(*this) = ++(*this);
		return temp;
	}

	Time operator-(Time &obj) {
		Time newTimeObj;
		int timeSubstraction, timeBorrow;

		timeSubstraction = seconds - obj.seconds;
		if (timeSubstraction < 0)
		{
			timeSubstraction = 60 + timeSubstraction;
			timeBorrow = 1;
			newTimeObj.seconds = timeSubstraction;
		} else {
			timeBorrow = 0;
			newTimeObj.seconds = timeSubstraction;
		}

		timeSubstraction = minutes - obj.minutes - timeBorrow;
		if (timeSubstraction < 0)
		{
			timeSubstraction = 60 + timeSubstraction;
			timeBorrow = 1;
			newTimeObj.minutes = timeSubstraction;
		} else {
			timeBorrow = 0;
			newTimeObj.minutes = timeSubstraction;
		}

		newTimeObj.hours = hours - obj.hours - timeBorrow;
		return newTimeObj;
	}

	Time operator--() {
		int timeSubstraction, timeBorrow;

		timeSubstraction = seconds - 1;
		if (timeSubstraction < 0)
		{
			timeSubstraction = 60 + timeSubstraction;
			timeBorrow = 1;
			seconds = timeSubstraction;
		} else {
			timeBorrow = 0;
			seconds = timeSubstraction;
		}

		timeSubstraction = minutes - timeBorrow;
		if (timeSubstraction < 0)
		{
			timeSubstraction = 60 + timeSubstraction;
			timeBorrow = 1;
			minutes = timeSubstraction;
		} else {
			timeBorrow = 0;
			minutes = timeSubstraction;
		}

		hours = hours - timeBorrow;

		return (*this);
	}

	// For post overator
	Time operator--(int)
	{
		Time temp = (*this);
		(*this) = --(*this);
		return temp;
	}


	friend ostream& operator<< (ostream& stream, const Time& obj);

};

ostream& operator<< (ostream& stream, const Time& obj) {
	stream << obj.hours << ":" << obj.minutes << ":" << obj.seconds;
	return stream;
}


int main() {
	// Hour : Minute : seconds
	Time obj1(0, 59, 35);
	Time obj2(1, 2, 3);

cout <<obj1<< endl;

cout <<obj2<< endl;

	Time obj3 = obj1 + obj2;

	cout << obj3 << endl;
	return 0;
}