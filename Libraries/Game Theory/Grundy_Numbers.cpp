// A Function to calculate Mex of all the values in 
// that set. 
//Mex is the smallet possible number that is not on a set

int calculateMex(unordered_set<int> Set) 
{ 
    int Mex = 0; 
  
    while (Set.find(Mex) != Set.end()) 
        Mex++; 
  
    return (Mex); 
} 

//this function changes from game to game
//on this case it calculates the mex of a NIM game of only one pile
//usually the grundy numbers are a DP or they need other algorithms to be discovered

int calculateGrundy(int n, int Grundy[])
{
	if (n == 0)
		return (0);
	
	if (Grundy[n] != -1)
		return (Grundy[n]);
	
	unordered_set<int> Set; // A Hash Table
	
	for (int i=0; i<=n-1; i++)
			Set.insert(calculateGrundy(i, Grundy));
	
	// Store the result
	Grundy[n] = calculateMex (Set);
	
	return(Grundy[n]);
}

//TIP : The xor sum of the grundy numbers of an impartial game determines the winner, if xor sum > 0 then first player wins, else second player wins


//Function that calculates the mex of a game where the player can take 1,2 or 3 stones

int calculateGrundy (int n, int Grundy[])
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);

	
	if (Grundy[n] != -1)
		return (Grundy[n]);
	
	unordered_set<int> Set; // A Hash Table
	
	for (int i=1; i<=3; i++)
			Set.insert (calculateGrundy (n-i, Grundy));
	
	// Store the result
	Grundy[n] = calculateMex (Set);
	
	return (Grundy[n]);
}

//Game where you divide n between 2,3 and 6, the first player to makes the divisions to go to 0 wins the game

int calculateGrundy (int n, int Grundy[])
{
	if (n == 0)
		return (0);
	
	if (Grundy[n] != -1)
		return (Grundy[n]);
	
	unordered_set<int> Set; // A Hash Table
	
	Set.insert (calculateGrundy (n/2, Grundy));
	Set.insert (calculateGrundy (n/3, Grundy));
	Set.insert (calculateGrundy (n/6, Grundy));
	
	// Store the result
	Grundy[n] = calculateMex (Set);	
	return (Grundy[n]);
}