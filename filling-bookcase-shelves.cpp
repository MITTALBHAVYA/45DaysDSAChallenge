class Solution
{
public:
    int solve(vector<vector<int>> &books, int index, int remWidth, int shelfWidth, int currMax)
    {
        if (index == books.size())
        {
            return currMax;
        }
        int nextMax = max(currMax, books[index][1]);
        if (remWidth >= books[index][0])
        {
            int placeOnCurrent = solve(books, index + 1, remWidth - books[index][0], shelfWidth, nextMax);
            int placeOnNewShelf = currMax + solve(books, index + 1, shelfWidth - books[index][0], shelfWidth, books[index][1]);

            return min(placeOnCurrent, placeOnNewShelf);
        }
        else
        {
            return currMax + solve(books, index + 1, shelfWidth - books[index][0], shelfWidth, books[index][1]);
        }
    }

    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        return solve(books, 0, shelfWidth, shelfWidth, 0);
    }
};
