//an example of a lambda, with interface.  testing two bools.
//jack kinne
public class Main {

    //acts an an abstract function, similiar to c++ declared funciton.
    interface NumericTest 
    {
        boolean computeTest(int n);
    }

    public static void main(String args[]) 
    {
        
        NumericTest isEven = (n) -> (n % 2) == 0;
        
        NumericTest isNegative = (n) -> (n < 0);

        // Output: false
        System.out.println(isEven.computeTest(5));

        // Output: true
        System.out.println(isNegative.computeTest(-5));
    }

    //a lambda is a short anonymous function.
    // specifically, a short form replacement for an anonymous class.
    // simplify the interface that declare a single abstract method

    //reusable, evaluated at runtime.  static or default typed method.

    // four functional interfaces:
    // Supplier<T>  no parameters, returns T, get
    // Consumer<T>  (T), returns void, accept
    // predicate<T> (T), returns boolean, test
    // function<T,R) (T), returns R, apply

    // cons:  costs cpu res than anon classes because its evaluated at runtime
    // cons:  harder to debug because error is not detected in compile time



}
