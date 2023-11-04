#include<iostream>
#include<unistd.h>
#include <sys/sysinfo.h>
using namespace std;
int main(){
	char hostname[256];
	gethostname(hostname, sizeof(hostname));
	struct sysinfo info;
	sysinfo(&info);

	cout << "Hostname:" << hostname << endl;
	cout << "RAM Total:" << info.totalram * info.mem_unit / (1024 * 1024) << " MB" << endl;
	cout << "RAM Livre:" << info.freeram * info.mem_unit / (1024 * 1024) << " MB" << endl;
	cout << "System uptime: " << info.uptime << " segundos" << endl;

	return 0;
}




