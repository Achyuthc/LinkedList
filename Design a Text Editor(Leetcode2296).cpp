
/*Design a text editor with a cursor that can do the following:

Add text to where the cursor is.
Delete text from where the cursor is (simulating the backspace key).
Move the cursor either left or right.
When deleting text, only characters to the left of the cursor will be deleted. The cursor will also remain within the actual text and cannot be moved beyond it. More formally, we have that 0 <= cursor.position <= currentText.length always holds.

Implement the TextEditor class:

TextEditor() Initializes the object with empty text.
void addText(string text) Appends text to where the cursor is. The cursor ends to the right of text.
int deleteText(int k) Deletes k characters to the left of the cursor. Returns the number of characters actually deleted.
string cursorLeft(int k) Moves the cursor to the left k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
string cursorRight(int k) Moves the cursor to the right k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
*/

class TextEditor {
public:
    list<char> dq;
  
    list<char>::iterator it;
    TextEditor() {
        dq.push_back('A');
        it=dq.end();
    }
    
    void addText(string text) {
      dq.insert(it,text.begin(),text.end());
    }
    
    int deleteText(int k) {
        int cnt = 0;
        // Move to the position that will be deleted.
        it--;
        while(k--){
            if(it==dq.begin())break;
            cnt++;
            dq.erase(it--);
        }
        // Adjust the position of the cursor.
        it++;
        return cnt;
        
    }
    string solve()   //Atel
    {
        int k=10;
        string str="";
        auto pt=it;
        pt--;
        while(k--)
        {
            if(pt==dq.begin())
            {
                break;
            }
            str.push_back(*pt);
            pt--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string cursorLeft(int k) {
        
        
        while(k--)
        {
            auto pt=it;
            pt--;
            if(pt==dq.begin())
                break;
            it=pt;
        }
        
        return solve();
        
    }
    
    string cursorRight(int k) {
     
        
        while(k--)
        {
            if(it==dq.end())
                break;
            it++;
        }
    
        return solve();
        
    }
};
