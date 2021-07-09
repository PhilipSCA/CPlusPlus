# Arithmetic Exam

Simple project, first of all I create the constant values.
### Constants
```cpp
const int MIN_VALUE = 1 -- Lowest number that can be given in a question
const int MAX_VALUE = 100 -- Highest number that can be given in a question
const int totalQuestions = 10; -- Total amount of questions
const std::vector<std::string> students{ "Charles","TJ","Nathan","Jaydan" }; -- List of all students
```
These are defined as constants as they won't change throughout the program.


### Seeding the system time
```cpp
unsigned seed = time(0);
```
I get the system time here to use as a seed for when I generate random numbers.

### Using a for loop to ask multiple questions
Next, I use a for loop to ask a set amount of questions, in this case its 10.
`const int totalQuestions = 10;`
```cpp
for (int i = 0; i < totalQuestions; i++) {
}
```

I seed the random number generator using the system time seed I created earlier, then generate a random number, which is either 0,1 or 2. This will be used as the mathematical operator (+,-,*)
```cpp
srand(seed);
int random = rand() % 3;
```

### Generating the random numbers to be used in the maths question
Next, I generate two more random numbers which will be used as the two numbers in the maths question.
```cpp
number_1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
number_2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
```
I ensure it's below the MAX_VALUE and above the MIN_VALUE here.

### Deciding the math operator and the correct answer expected
Random variable was defined above, which set the operation.
The expected answer is also set based on the operation used.
```cpp
switch (random) {
    case 0:
        math_op = '+';
        expectedAnswer = number_1 + number_2;
        break;
    case 1:
        math_op = '-';
        expectedAnswer = number_1 - number_2;
        break;
    default:
        math_op = '*';
        expectedAnswer = number_1 * number_2;
        break;
}
```


### Outputting result
```cpp
//Create result variable
std::string result;
if (enteredAnswer == expectedAnswer) {
    result = "Correct\n ";
    //Add a correct Answer
    correctAnswers++;
}
else {
    result = "Incorrect\n";
}
//Outputting result
std::cout << result;
```

### Calculating Average
``cpp
//Average initially as a float, round it after. Although there are 10 questions now it will always be a whole number, but if totalQuestions is changed it won't be.
float average = (correctAnswers / static_cast<float>(totalQuestions)) * 100; //Casting totalQuestions to float
std::cout << "\nTotal Average: " << round(average) << "%\n"; //Rounding average to nearest 1, in case of decimal
```
