//Time Complexity-O(m*n*(3^L)) --> here m-No of rows,n-no of columns,L-length of word
//Space Complexity-O(L)-->length of word
//Did the code execute on Leetcode? yes

class Solution {
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        bool a=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    a=dfs(board,i,j,0,word);
                    if(a==1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    bool dfs(vector<vector<char>>& board,int i,int j,int count,string word)
    {
        if(count==word.length())
        {
            return 1;
        }
        if(i<0 || i>=board.size()|| j<0 || j>=board[i].size() || board[i][j]!=word[count])
        {
            return 0;
        }
        char temp=board[i][j];
        board[i][j]='#';
        bool res=dfs(board,i+1,j,count+1,word)||
                 dfs(board,i-1,j,count+1,word)||
                 dfs(board,i,j+1,count+1,word)||
                 dfs(board,i,j-1,count+1,word);
        board[i][j]=temp;
        return res;
    }
};