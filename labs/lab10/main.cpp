#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <boost/chrono/system_clocks.hpp>

// Fibonacci definitions from
// http://planet.jboss.org/post/fibonacci_sequence_with_and_without_recursion

int fibNonRecurse(int n)
{
    if(n <= 1)
    {
        return n;
    }
    int fib = 1;
    int fibPrev = 1;
    for(int i = 2; i < n; ++i)
    {
        int temp = fib;
        fib += fibPrev;
        fibPrev = temp;
    }

    return fib;
}

int fibRecurse(int n){

    if(n <= 1){
        return n;
    }else{
        return fibRecurse(n-1) + fibRecurse(n-2);
    }
}

double rfactorialNonTail(int n) {
    if(n == 1)
        return 1;
    else
        return n * rfactorialNonTail(n-1);
}

// Factorial definitions from assignment

double rfactorialTailHelper(double n, double result)
{
    if(n == 1)
        return result;
    else
        return rfactorialTailHelper(n-1, n*result);
}

double rfactorialTail(double n)
{
    return rfactorialTailHelper(n, 1);
}



int main()
{
    std::ofstream fibRecurseFile;
    std::ofstream fibNonRecurseFile;
    std::ofstream facNonTailFile;
    std::ofstream facTailFile;

    fibRecurseFile.open("results-fib-recurse.csv");
    fibNonRecurseFile.open("results-fib-nonrecurse.csv");
    facNonTailFile.open("results-fac-nontail.csv");
    facTailFile.open("results-fac-tail.csv");

    fibRecurseFile << "iteration,value,time\n";
    fibNonRecurseFile << "iteration,value,time\n";
    facNonTailFile << "iteration,value,time\n";
    facTailFile << "iteration,value,time\n";



    for(int i = 1; i < 30; i++) {
        int fibNonRecurseVal;
        
        boost::chrono::steady_clock::time_point t1 = boost::chrono::steady_clock::now();
        fibNonRecurseVal = fibNonRecurse(i);
        boost::chrono::steady_clock::time_point t2 = boost::chrono::steady_clock::now();
        boost::chrono::duration<double> durationFibNonRecurse = boost::chrono::duration_cast<boost::chrono::duration<double>>(t2-t1);
        std::cout << fibNonRecurseVal << std::endl;
        std::cout << "Total time was " << std::fixed << std::setprecision(10) << durationFibNonRecurse.count() << " clicks. (Fib non-recursive)" << std::endl;
        fibNonRecurseFile << std::fixed << std::setprecision(10) << i << "," << fibNonRecurseVal << "," << durationFibNonRecurse.count() << "\n";

        int fibRecurseVal;
        boost::chrono::steady_clock::time_point p1 = boost::chrono::steady_clock::now();
        fibRecurseVal = fibRecurse(i);
        boost::chrono::steady_clock::time_point p2 = boost::chrono::steady_clock::now();
        boost::chrono::duration<double> durationFibRecurse = boost::chrono::duration_cast<boost::chrono::duration<double>>(p2-p1);
        std::cout << fibRecurseVal << std::endl;
        std::cout << "Total time was " << std::fixed << durationFibRecurse.count() << " clicks. (Fib recursive)" << std::endl;
        fibRecurseFile << std::fixed << std::setprecision(10) << i << "," << fibRecurseVal << "," << durationFibRecurse.count() << "\n";

        double facNonTail;
        boost::chrono::steady_clock::time_point x1 = boost::chrono::steady_clock::now();
        facNonTail = rfactorialNonTail(i);
        boost::chrono::steady_clock::time_point x2 = boost::chrono::steady_clock::now();
        boost::chrono::duration<double> durationFacNonTail = boost::chrono::duration_cast<boost::chrono::duration<double>>(x2-x1);
        std::cout << facNonTail << std::endl;
        std::cout << "Total time was " << std::fixed << durationFacNonTail.count() << " clicks. (Fac Non-Tail recursive)" << std::endl;
        facNonTailFile << std::fixed << std::setprecision(10) << i << "," << facNonTail << "," << durationFacNonTail.count() << "\n";

        double facTail;
        boost::chrono::steady_clock::time_point y1 = boost::chrono::steady_clock::now();
        facTail = rfactorialTail(static_cast<double>(i));
        boost::chrono::steady_clock::time_point y2 = boost::chrono::steady_clock::now();
        boost::chrono::duration<double> durationFacTail = boost::chrono::duration_cast<boost::chrono::duration<double>>(y2-y1);
        std::cout << facTail << std::endl;
        std::cout << "Total time was " << std::fixed << durationFacTail.count() << " clicks. (Fac Tail recursive)" << std::endl;
        facTailFile << std::fixed << std::setprecision(10) << i << "," << facTail << "," << durationFacTail.count() << "\n";

    }

    facTailFile.close();
    facNonTailFile.close();
    fibNonRecurseFile.close();
    fibRecurseFile.close();

    return 0;
}

