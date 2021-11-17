#include <bits/stdc++.h>
#include <exception>
#include <stdexcept>

using namespace std;

void exception_handler(std::exception_ptr e)
{
  try
  {
    std::rethrow_exception(e);
  }
  catch (const std::logic_error& e )
  {
    cout << "logic error" <<endl;
  }
  catch (const std::runtime_error& e )
  {
    cout << "runtime error" <<endl;
  }
  catch (... )
  {
    cout << "other error" <<endl;
  }
}

#define MAX_RECONNECT_ATTEMPTS 3
void myfunction()
{
  for (auto attempts = 0; attempts < MAX_RECONNECT_ATTEMPTS ;attempts++)
  {
    try{
      // do command

      cout<< "output thing" << endl;
      //throw std::logic_error{""};
      break;
    }
    catch( ... )
    {
      cout << "Something went wrong ... retrying x"<< attempts <<endl;
//      if ( attempts == MAX_RECONNECT_ATTEMPTS - 1 )
        exception_handler(std::current_exception());
    }
  }
}

int main()
{
  myfunction();

  return 0;
}
