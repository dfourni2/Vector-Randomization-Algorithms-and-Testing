# Vector-Randomization-Algorithms-and-Testing\

This project was created to understand how different randomization algorithms compare to eachother exclusively written in C++. Each group member created their own randomization algorithm then we created a way to test how effective each one was at randomizing a vector. Comments and print statements in the main class and random header file point out which group member wrote each algorithm. The test function that we wrote goes through 5000 iterations of randomizing the vector. This then analyzes truely how random the vectors were. The "perfectly" random algorithm would get a score of 0.05. The results of testing our two best algorithms are seen below.

# Testing Results:
bksoucyRand()

Overall wasn't super effective. But I did also write it from scratch, so cut me some slack lol
Was always +/- 0.05, 10/10 trials that I ran which sounds good being <5% error. But in comparison to other random algorithms than use the built in rand it is lacking
For example, out of the 10 trials my algorithm was only within 0.01 4/10 times, and within 0.0005 3/10 times,
Overall, is a decent algorithm however definitely could be improved.
dfourniRand()

My algorithm was slightly more effective when comparing it quantitatively
In 10 trials, the average difference between the expected .05 score and the actual test result was 0.00202
However, like the bksoucyRand() function, only 3/10 trials were within 0.0005 of the expected 0.05
The main difference was just that there was more consistancy with this method. There were no trials where the difference was greater than 0.01 away from the expected 0.05 score
Overall, this is an effective algorithm however, as with almost every code, there could be improvements to make it nearly perfect randomness
