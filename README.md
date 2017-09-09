# pw_manager
Password manager using C++ as interface for interacting with a secure SQL database.

Password manager is a simple, fully functionaing program that helps users store passwords
for various sites and usernames or emails. Using c++ as an interface to interact with a
sequre SQLite database, user can input passwords into the program which are then encrypted
using a simple, yet slightly modified XOR cipher. Only a single character key is needed to
store and retrieve back any given password.

Development was done in C++ as a way to hone c++ skills, yet also learn how to use it to
work with databases. Visual Studio was used to create the basic GUI for the program.
Although not exactly pretty, the program works as intended. Python was also used for the
command line/non-GUI version of the program in order to get a head start in creating the
database since the sqlite3 library in python is much easier to understand and use.

There are an endless amount of improvements that can still be made however. The GUI does look
awful, but can eventually be made into an at least, nicer looking program with more security
such as hiding passwords when being inputted as well as confirmation options. The entirety
of the GUI programming can also be optimized as the database is opened and closed each
time an event happens. The SiteData class can also be optimized as well through cleaner code
which will hopefully come in time through better understanding of C++.
