#include <bits/stdc++.h>
using namespace std;
void file_i_o() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// Flight class
class Flight {
    private:
        string flightNumber;
        string departureCity;
        string arrivalCity;
        string departureTime;
        string arrivalTime;
        string flightStatus;
        int seatsAvailable;
    public:

        Flight() {
            flightNumber = "";
            departureCity = "";
            arrivalCity = "";
            departureTime = "";
            arrivalTime = "";
            flightStatus = "";
            seatsAvailable = 0;
        }


        Flight(string flightNumber, string departureCity, string arrivalCity,
                string departureTime, string arrivalTime, string flightStatus, int seatsAvailable) {
            this->flightNumber = flightNumber;
            this->departureCity = departureCity;
            this->arrivalCity = arrivalCity;
            this->departureTime = departureTime;
            this->arrivalTime = arrivalTime;
            this->flightStatus = flightStatus;
            this->seatsAvailable = seatsAvailable;
        }

        string getFlightNumber() {
            return flightNumber;
        }

        string getDepartureCity() {
            return departureCity;
        }

        string getArrivalCity() {
            return arrivalCity;
        }

        string getDepartureTime() {
            return departureTime;
        }

        string getArrivalTime() {
            return arrivalTime;
        }

        string getFlightStatus() {
            return flightStatus;
        }

        int getSeatsAvailable() {
            return seatsAvailable;
        }
};

// Passenger class
class Passenger {
    private:
        string name;
        string bookingStatus;
        string seatNumber;
    public:
        Passenger() {}  // Default constructor
        Passenger(string name, string bookingStatus, string seatNumber) {
            this->name = name;
            this->bookingStatus = bookingStatus;
            this->seatNumber = seatNumber;
        }

        string getName() {
            return name;
        }

        string getBookingStatus() {
            return bookingStatus;
        }

        string getSeatNumber() {
            return seatNumber;
        }
};

// Booking class
class Booking {
    private:
        string bookingNumber;
        Passenger passenger;
        Flight flight;
        string paymentDetails;
    public:
        Booking(string bookingNumber, Passenger passenger, Flight flight, string paymentDetails) {
            this->bookingNumber = bookingNumber;
            this->passenger = passenger;
            this->flight = flight;
            this->paymentDetails = paymentDetails;
        }

        string getBookingNumber() {
            return bookingNumber;
        }

        Passenger getPassenger() {
            return passenger;
        }

        Flight getFlight() {
            return flight;
        }

        string getPaymentDetails() {
            return paymentDetails;
        }
};

// Staff class
class Staff {
    private:
        string name;
        string staffID;
    public:
        Staff(string name, string staffID) {
            this->name = name;
            this->staffID = staffID;
        }

        string getName() {
            return name;
        }

        string getStaffID() {
            return staffID;
        }
};

int main() {
    file_i_o();
    // Creating objects of classes
    //      flightNumber departureCity arrivalCity departureTime arrivalTime flightStatus seatsAvailable
    Flight flight("AI101", "Delhi", "London", "10:00", "15:00", "On-time", 200);
    // string name, string bookingStatus, string seatNumber
    Passenger passenger("John Doe", "Confirmed", "A1");
    // string bookingNumber, Passenger passenger, Flight flight, string paymentDetails
    Booking booking("B001", passenger, flight, "Credit Card");
    Staff staff("Jane Doe", "S001");

    // Accessing class data through objects
    cout << "Flight Number: " << flight.getFlightNumber() << endl;
    cout << "Departure City: " << flight.getDepartureCity() << endl;
    cout << "Arrival City: " << flight.getArrivalCity() << endl;
    cout << "Departure Time: " << flight.getDepartureTime() << endl;
    cout << "Arrival Time: " << flight.getArrivalTime() << endl;
    cout << "Flight Status: " << flight.getFlightStatus() << endl;
    cout << "Seats Available: " << flight.getSeatsAvailable() << endl;
    cout << endl;

    cout << "Passenger Name: " << passenger.getName() << endl;
    cout << "Booking Status: " << passenger.getBookingStatus() << endl;
    cout << "Seat Number: " << passenger.getSeatNumber() << endl;
    cout << endl;

    cout << "Booking Number: " << booking.getBookingNumber() << endl;
    cout << "Passenger Name: " << booking.getPassenger().getName() << endl;
    cout << "Flight Number: " << booking.getFlight().getFlightNumber() << endl;
    cout << "Payment Details: " << booking.getPaymentDetails() << endl;
    cout << endl;

    cout << "Staff Name: " << staff.getName() << endl;
    cout << "Staff ID: " << staff.getStaffID() << endl;
    cout << endl;

    return 0;
}