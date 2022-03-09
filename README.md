# create-exam-system
Creating system to help teachers make exam for students in different classes, then students can take the exam, system will compare answers and order the grades with students mistakes in file - using OS Linux(centos7) 

CreateExam : 
imput: Exam file name, exam subject, exam author name.Asks the user to enter the desired number of questions
Then lets the user pick up question and 4 Possible answers. 

Output: the command will create a copy of the exam, by name Exam file.

SolExam : 
Input: Exam file name, asks the user to enter the number. The correct answer to any question in order, i.e. first number for first question.
This command identifies the number of questions in the exam and according to this number allows
For the user to enter answers.

Output: save a copy named "SOL_exam_name" that contains the number of the correct answer in order from question 1 to last.

StartExam : 
Input : Exam name, operation name, command will open the answers file by exam name (exam name combined with _Sol) will count the number of correct answers by comparing the student solution to the answer file.

Output: Print to a file named "Name" Exam_name_performs_grade "the number of correct answers.

CalcGrade: 
Input: Exam file name, operation name, will open the test file generated from the previous command.

Output: By the number of questions you will calculate the final score of the exam,
Add it to the end of the test file with the message: Grade Final. 
In addition, you will display on the screen the student name Exam name and final grade.

Goodbye:
This command exits the program, closes the shell_Advanced, and returns to the original shell.

Developed a new shell, the shell will support all existing commands in the regular shell,
But will expand its capabilities with additional commands that do not exist in it.
