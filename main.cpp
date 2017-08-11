#include <python2.7/Python.h>

using namespace std;

int main(int argc, char **argv) {

	Py_Initialize();
	if (ifstream("pw.db")) {

	} else {
    /*
		FILE * pyFile = fopen("test.py", "r");
		PyRun_SimpleFile(pyFile, "test.py");
		fclose(pyFile);
    */
	}

	Py_Finalize();
	return 0;
}
