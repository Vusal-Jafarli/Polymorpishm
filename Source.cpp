#include <iostream>
#include <cassert>
#include<vector>
using namespace std;

class Car {
	static int _static_id_car;
	int _id;
	string _marka;
	string _model;
	string _color;
	bool _hasSpoiler;



public:
	Car() {
		_id = 0;
		_marka = "";
		_model = "";
		_color = "";
		_hasSpoiler = false;
	}
	Car(string marka, string model, string color, bool has_spoiler) {



		_id = _static_id_car++;
		set_marka(marka);
		set_model(model);
		set_color(color);
		_hasSpoiler = has_spoiler;
	}



	void set_marka(string marka) {
		if (marka.size() > 2 && marka.size() < 100) {
			_marka = marka;
			return;
		}
		assert(!"Incorrect initializing.");
	}
	void set_model(string model) {
		if (model.size() > 0 && model.size() < 100) {
			_model = model;
			return;
		}
		assert(!"Incorrect initializing.");
	}
	void set_color(string color) {
		if (color.size() > 0 && color.size() < 100) {
			_color = color;
			return;
		}
		assert(!"Incorrect initializing.");
	}



	string get_marka() { return _marka; }
	string get_model() { return _model; }
	string get_color() { return _color; }
	int get_id() { return _id; }
	bool get_spoiler_info() { return _hasSpoiler; }



	void show() {
		cout << "Car ID: " << _id << endl
			<< "Marka: " << _marka << endl
			<< "Model: " << _model << endl
			<< "Color: " << _color << endl;
		cout << "Spoiler: ";
		_hasSpoiler == true ? cout << "VAR" << endl : cout << "VAR" << endl;
	}




};
int Car::_static_id_car = 1;



class Date {
	int _day = 0;
	int _month = 0;
	int _year = 0;
public:
	Date() {
		_day = 0;
		_month = 0;
		_year = 0;
	}
	Date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}

	int get_day() { return _day; }
	int get_month() { return _month; }
	int get_year() { return _year; }
};

class Manuel :public Car {
	int _gear_count;


public:
	Manuel(string marka, string model, string color, bool has_spoiler, int gear_count) :Car(marka, model, color, has_spoiler) {
		_gear_count = gear_count;
	}

	virtual void show() {
		Car::show();
		cout << "Speed Box: Manuel" << endl;
		cout << "Gear Count: " << _gear_count << endl;

	}
};

class Automatic : public Car {
	bool _has_auto_pilot;



public:
	Automatic(string marka, string model, string color, bool has_spoiler, bool has_auto_pilot) :Car(marka, model, color, has_spoiler) {
		_has_auto_pilot = has_auto_pilot;
	}

	virtual void show() {
		Car::show();
		cout << "Speed Box: Automatic" << endl;
		cout << "Auto Pilot: ";
		_has_auto_pilot == true ? cout << " VAR" << endl : cout << " YOXDUR" << endl;

	}

};


class  Mercedes :public Automatic {
	Date oil_change_time;

public:


	Mercedes(string marka, string model, string color, bool has_spoiler, bool has_auto_pilot, Date date)
		:Automatic(marka, model, color, has_spoiler, has_auto_pilot), oil_change_time(date) {}

	void show() override {
		Automatic::show();
		cout << "Oil Changed Time: " << oil_change_time.get_day() << "."
			<< oil_change_time.get_month() << "." << oil_change_time.get_year() << endl;
	}

	friend ostream& operator<<(ostream& os, Mercedes& mercedes);

};
ostream& operator<<(ostream& os, Mercedes& mercedes) {
	mercedes.Automatic::show();
	cout << "Oil Changed Time: " << mercedes.oil_change_time.get_day() << "."
		<< mercedes.oil_change_time.get_month() << "." << mercedes.oil_change_time.get_year() << endl;
	return os;
}


class  BMW :public Automatic {
	int _speed_rating = 0;

public:
	BMW(string marka, string model, string color, bool has_spoiler, bool has_auto_pilot, int speed_rating)
		:Automatic(marka, model, color, has_spoiler, has_auto_pilot), _speed_rating(speed_rating) {}

	void show()override {
		Automatic::show();
		cout << "Speed Rating: " << _speed_rating << endl;
	}
	friend ostream& operator<<(ostream& os, BMW& bmw);
};
ostream& operator<<(ostream& os, BMW& bmw) {
	bmw.Automatic::show();
	os << "Speed Rating: " << bmw._speed_rating << endl;
	return os;
}


class ElektroTruck :public Manuel {
	size_t _battery_count = 0;

public:
	ElektroTruck(string marka, string model, string color, bool has_spoiler, int gear_count, int battery_count)
		:Manuel(marka, model, color, has_spoiler, gear_count) {
		_battery_count = battery_count;
	}

	void show()override {
		Manuel::show();
		cout << "Battery Count: " << _battery_count << endl;
	}
	friend ostream& operator<<(ostream& os, ElektroTruck& ts);

};
ostream& operator<<(ostream& os, ElektroTruck& ts) {
	ts.Manuel::show();
	os << "Battery Count: " << ts._battery_count << endl;
	return os;
}



class Base {
public:
	vector<BMW>bmw;
	vector<Mercedes>mercedes;
	vector<ElektroTruck>elektroTruck;

	Base() = default;
	Base(vector<BMW>bmw, vector<Mercedes>mercedes, vector<ElektroTruck>elektroTruck) :bmw(bmw), mercedes(mercedes), elektroTruck(elektroTruck) {}


	//Base cllasinin methodu ile show()
	void show() {

		cout << "\t\t" << "--------------------" << endl << endl;
		cout << "\t\t" << "---------BMW--------" << endl << endl;
		cout << "\t\t" << "--------------------" << endl << endl;
		for (size_t i = 0; i < bmw.size(); i++) { cout << bmw[i] << endl; }

		cout << "\t\t" << "----------------------" << endl << endl;
		cout << "\t\t" << "-------Mercedes-------" << endl << endl;
		cout << "\t\t" << "----------------------" << endl << endl;
		for (size_t i = 0; i < mercedes.size(); i++) { cout << mercedes[i] << endl; }

		cout << "\t\t" << "--------------------------" << endl << endl;
		cout << "\t\t" << "-------ElektroTruck-------" << endl << endl;
		cout << "\t\t" << "--------------------------" << endl << endl;
		for (size_t i = 0; i < elektroTruck.size(); i++) { cout << elektroTruck[i] << endl; }
	}


};



//Funksiya vasitesile show()

void show_Base(Base& base) {
	base.show();
}


void main() {

	//                    BMW                    //
	string bmw_name = "BMW";
	string bmw_name2 = "BMW";
	string bmw_model = "I3";
	string bmw_model2 = "X5";
	string bmw_color = "White";
	string bmw_color2 = "BLUE";

	BMW bmw(bmw_name, bmw_model, bmw_color, true, true, 5);
	BMW bmw2(bmw_name2, bmw_model2, bmw_color2, false, true, 13);

	vector<BMW>bmw_vector;
	bmw_vector.push_back(bmw);
	bmw_vector.push_back(bmw2);

	//                                             //


	//                  MERCEDES                   //

	string mercedes_name = "Mercedes";
	string mercedes_model = "C Class";
	string mercedes_model2 = "E Class";
	string mercedes_color = "Black";
	string mercedes_color2 = "Red";
	Date oil_dt(11, 6, 2023);
	Date oil_dt2(19, 1, 2023);


	Mercedes mercedes(mercedes_name, mercedes_model, mercedes_color, true, true, oil_dt);
	Mercedes mercedes2(mercedes_name, mercedes_model2, mercedes_color2, false, true, oil_dt2);

	vector<Mercedes>mercedes_vector;
	mercedes_vector.push_back(mercedes);
	mercedes_vector.push_back(mercedes2);

	//                ElektroTruck                            //

	string e_truck_name = "Mercedes";
	string e_truck_model = "C Class";
	string e_truck_model2 = "E Class";
	string e_truck_color = "Black";
	string e_truck_color2 = "Red";

	ElektroTruck elektroTruck(e_truck_name, e_truck_model, e_truck_color, false, 5, 26);
	ElektroTruck elektroTruck2(e_truck_name, e_truck_model2, e_truck_color2, false, 6, 40);


	vector<ElektroTruck>electro_vector;
	electro_vector.push_back(elektroTruck);
	electro_vector.push_back(elektroTruck2);

	Base base(bmw_vector, mercedes_vector, electro_vector);

	//base.show();



	//base.bmw[0].show();
	//base.mercedes[0].show();



	Date oil_dt11(11, 6, 2023);
	Car** base11 = new Car * [5] {};
	base11[0] = new Mercedes("Mercedes", "CLS", "BLUE", true, true, oil_dt11);
	base11[2] = new Mercedes("Mercedes", "CLS", "BLUE", true, true, oil_dt11);
	base11[3] = new BMW("BMW", "X5", "WHITE", false, true, 3);
	base11[1] = new BMW("BMW", "X7", "BLACK", true, true, 3);
	base11[4] = new ElektroTruck("Electro", "CyberTruck", "GRAY", false, 6, 4);

	base11[0]->show();
	cout << endl;
	cout << endl;

	base11[4]->show();





}