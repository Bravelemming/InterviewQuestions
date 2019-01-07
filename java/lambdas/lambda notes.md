# what are lambda's?
:  a lambda is a short anonymous function.  
<<<<<<< HEAD
:  replaces anonymous classes.
=======
>>>>>>> b8c23f1fddf76c3d8961171d8882d495463d6d3b

## why's it awesome?
:  basically allows for a paradigm shift from object oriented programming to functional programming, which as a C++ programmer I love.

## simple design:
:  you only need three things to make a lambda: 
- (parenthesis) holding parameters for none or many; one doesn't need them.
- arrow operator `->`
- {function;}, or just your function(); and no brackets for single lines of code.  
- one way to think about it: n becomes n times n.  `n -> n*n;`

---

## pros:
- less to code, saves time.
- easier to read. 
- allows functional programming.
<<<<<<< HEAD
- reusable, evaluated at runtime. 
=======
>>>>>>> b8c23f1fddf76c3d8961171d8882d495463d6d3b


## cons: 
- more overhead; because they are compiled at runtime, they use system resources.
<<<<<<< HEAD
- harder to debug because error is not detected in compile time
=======
- harder to fix; also because they are compiled at runtime, it's harder to find errors.
>>>>>>> b8c23f1fddf76c3d8961171d8882d495463d6d3b

---
## short example:

~~~
interface NumericTest {
	boolean computeTest(int n); 
}

public static void main(String args[]) {
	NumericTest isEven = (n) -> (n % 2) == 0;
	NumericTest isNegative = (n) -> (n < 0);

	// Output: false
	System.out.println(isEven.computeTest(5));

	// Output: true
	System.out.println(isNegative.computeTest(-5));
}
~~~


---

## good questions:
: in c++, you can control if a lambda passes by value or reference with a simple star or amperstand, but in java, how do you know if you're passing by reference or value?  Can you change it?