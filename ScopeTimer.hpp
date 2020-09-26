/*
  ScopeTimer.hpp
  Joel Goodman, 2020

  @brief This is a class I use to time te execution of scopes.
*/
#ifndef SCOPETIMER_HPP
#define SCOPETIMER_HPP

#include <iostream>
#include <chrono>


class ScopeTimer
{
public:
  enum Increment
  {
    Nanoseconds = 0,
    Microseconds,
    Milliseconds,
    Seconds,
    Minutes,
    Hours
  };

private:
  const Increment m_increment;
  const std::string m_msg;
  const std::chrono::high_resolution_clock::time_point m_start;

public:
  ScopeTimer(const Increment increment=Milliseconds, const std::string& msg="scope") :
    m_increment(increment),
    m_msg(msg),
    m_start(std::chrono::high_resolution_clock::now())
  {}

  ~ScopeTimer()
  {
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    const std::string preMsg = "Execution time (" + m_msg + ") = ";

    using std::cout;
    switch(m_increment)
    {
      case Nanoseconds:
      {
        const auto nsTotal = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - m_start).count();
        cout << preMsg << nsTotal << ' ' <<  " nanoseconds.\n";
      }
        break;
      case Microseconds:
      {
        const auto usTotal = std::chrono::duration_cast<std::chrono::microseconds>(stop - m_start).count();
        cout << preMsg << usTotal << ' ' << " microseconds.\n";
      }
        break;
      case Milliseconds:
      {
        const auto msTotal = std::chrono::duration_cast<std::chrono::milliseconds>(stop - m_start).count();
        cout << preMsg << msTotal << ' ' << " milliseconds.\n";
      }
        break;
      case Seconds:
      {
        const auto sTotal = std::chrono::duration_cast<std::chrono::seconds>(stop - m_start).count();
        cout << preMsg << sTotal << " seconds.\n";
      }
        break;
      case Minutes:
      {
        const auto mTotal = std::chrono::duration_cast<std::chrono::minutes>(stop - m_start).count();
        cout << preMsg << mTotal << " minutes.\n";
      }
        break;
      case Hours:
      {
        const auto hTotal = std::chrono::duration_cast<std::chrono::hours>(stop - m_start).count();
        cout << preMsg << hTotal << " hours.\n";
      }
        break;
      default:
        cout << "No increment specified for ScopeTimer.\n";
    } /* Switch */
  } /* Destructor */
};


#endif /* SCOPETIMER_HPP */