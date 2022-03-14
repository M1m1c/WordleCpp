# WordleCpp
By Ludvig Baummann Olsson

When choosing what container class to use for storing the words from the file I made the following observations:
The container should only allow unqiue instances of words, no duplicates.
The container should be quick at finding or looking at contained items, since comparing input to the words in the container is how we determine valid input.

I then did some research online and found that perhaps an unordered set was what I was looking for.
It would not matter in what order the words existed in the container as long as it was quick to find them.
I decided to try my hand at making something akin to an unorderd set of my own.

It turned out to maybe not be the best container to use for this case, however I was determined to make it work.
The first problem I encountered was when trying to create unqiue hashes for each word.
I was unable to make or find an algorithm that would have all the hashes be unqiue and cramed into a container of the same size as the number of words I had available.
Every solution I could come up with for handeling the hash collisions felt like they were detracting from the benefits of using an unordered set.
In the end I decided to make the hash set large enough to avoid hash collisions alltogether for the words I was using.
The capacity I settled on that would allow me to avoid collision was 50000000, 
which I feel is probably too big however this was a sacrifice I was willing to make after having spent so long trying come up with a better solution.

The second problem was something that I had failed to observe in my initial analysis, which was that we needed to be able to pick a random word from the container.
Since the capacity of the container was now very big and contained alot of empty indecies I would not bable to simply randomise an index like normally.
After some deliberation I decided that the simplest solution would be to store the hash generated indecies of the words in a seperate container and randomise over those.

My reasoning for sticking with the container solution that I initially chose was multifaceted.
The most important reason was that the game needed to be quick when comparing input which happens every time the player enters a word.
Randomisation of words only happens when a new game starts therefore it is not as important that that aspect is quick.
Finaly I was determined to learn better how hashsets worked since I had never used them before.

In the end I can't really say if using an unorderd set was the right solution for this task, but it is the one I went with.
I had to make some concesions such as the storing of the indecies in a seperate container that turned it into more of a hybrid rather than a pure unorderd set.
