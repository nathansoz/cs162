#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <fstream>

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



    for(int i = 1; i < 30; i++)
    {
        int fibNonRecurseVal;

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        fibNonRecurseVal = fibNonRecurse(i);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationFibNonRecurse = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        std::cout << fibNonRecurseVal << std::endl;
        std::cout << "Total time was " << std::fixed << std::setprecision(10) << durationFibNonRecurse.count() << " clicks. (Fib non-recursive)" << std::endl;
        fibNonRecurseFile << std::fixed << std::setprecision(10) << i << "," << fibNonRecurseVal << "," << durationFibNonRecurse.count() << "\n";

        int fibRecurseVal;
        std::chrono::high_resolution_clock::time_point p1 = std::chrono::high_resolution_clock::now();
        fibRecurseVal = fibRecurse(i);
        std::chrono::high_resolution_clock::time_point p2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationFibRecurse = std::chrono::duration_cast<std::chrono::duration<double>>(p2 - p1);
        std::cout << fibRecurseVal << std::endl;
        std::cout << "Total time was " << std::fixed << durationFibRecurse.count() << " clicks. (Fib recursive)" << std::endl;
        fibRecurseFile << std::fixed << std::setprecision(10) << i << "," << fibRecurseVal << "," << durationFibRecurse.count() << "\n";
    }
    for(int i = 100000; i < 100050; i++)
    {
        double facNonTail;
        std::chrono::high_resolution_clock::time_point x1 = std::chrono::high_resolution_clock::now();
        facNonTail = rfactorialNonTail(static_cast<double>(i));
        std::chrono::high_resolution_clock::time_point x2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationFacNonTail = std::chrono::duration_cast<std::chrono::duration<double>>(x2-x1);
        std::cout << facNonTail << std::endl;
        std::cout << "Total time was " << std::fixed << durationFacNonTail.count() << " clicks. (Fac Non-Tail recursive)" << std::endl;
        facNonTailFile << std::fixed << std::setprecision(10) << i << "," << facNonTail << "," << durationFacNonTail.count() << "\n";

        double facTail;
        std::chrono::high_resolution_clock::time_point y1 = std::chrono::high_resolution_clock::now();
        facTail = rfactorialTail(static_cast<double>(i));
        std::chrono::high_resolution_clock::time_point y2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationFacTail = std::chrono::duration_cast<std::chrono::duration<double>>(y2-y1);
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

