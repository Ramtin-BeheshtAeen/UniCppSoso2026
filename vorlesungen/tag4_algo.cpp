#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <random>
#include <vector>
#include <numeric>

using namespace std;

class Counter {
  int start, step;
public:
  Counter(int st, int ste) : start(st), step(ste) {}
  int operator()()  {
    int old = start;
    start  = start + step;
    return old;
   }
};


int main() {
  vector<double> grades = {1.3, 2.0, 1.7, 3.0, 2.3};

  double sum_float = accumulate(grades.cbegin(), grades.cend(), 0.0);
  double sum_int   = accumulate(grades.cbegin(), grades.cend(), 0);
  cout << "sum with 0.0: " << sum_float << "\n";
  cout << "sum with 0:   " << sum_int << "\n";
  cout << "average:      " << sum_float / grades.size() << "\n";

  // lambda: count how many grades are better than (smaller than) a limit
  //count_if is new. It counts how many elements make the lambda return true
  double limit = 2.0;
  auto good    = count_if(grades.begin(), grades.end(), [limit](double g){return g < limit;} );
  cout << "better than " << limit << ": " << good << "\n";


  vector<int> tickets;
  generate_n(inserter(tickets, tickets.end()), 5, Counter(10, 5));
  copy(tickets.begin(), tickets.end(), ostream_iterator<int>(cout, ", "));
  cout << "\n";

  //product of tickets:
  int product = accumulate(tickets.begin(), tickets.end(), 1,
			   [](int acc, int x){return acc * x;} );

  cout << "product of seats: " << product << "\n";


}
