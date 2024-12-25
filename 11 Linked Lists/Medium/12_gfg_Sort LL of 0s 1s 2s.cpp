//Brute Force using count
class Solution {
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0)
                c0++;
            else if (temp->data == 1)
                c1++;
            else
                c2++;

            temp = temp->next;
        }
        temp = head;
        while (temp != NULL) {
            if (c0) {
                temp->data = 0;
                Q c0--;
            } else if (c1) {
                temp->data = 1;
                c1--;
            } else {
                temp->data = 2;
                c2--;
            }
            temp = temp->next;
        }

        return head;
    }
};


//Optimal 
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s, and 2s
    static Node* segregate(Node* head) {
        // Creating three separate dummy nodes
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        //Pointers that will move along till last Node 
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            } else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            } else if (temp->data == 2) {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }

        // Merging the sublists

        //Handling 1s list..present or absent
        if (oneHead->next != nullptr) {
            zero->next = oneHead->next;  //even if no 0s...zeroDummyHead points to nullptr..thus it is replaced by this step..that is zero cha next is now oneDummyhead next.or if 1s absent dont step used
        } else {
            zero->next = twoHead->next;
        }
        one->next = twoHead->next; //The 1s list is always connected to the 2s list, regardless of whether it contains nodes:
        two->next = nullptr;

        // Returning the new head of the sorted list
        return zeroHead->next;
    }
};

=====================================================================

        // Merging the sublists
        if (oneHead->next != nullptr) {
            zero->next = oneHead->next;  //initially   zero->next will be nptr if no zeros
        } else {
            zero->next = twoHead->next;
        }
        one->next = twoHead->next;    //initially   one->next will be nptr if no ones
        two->next = nullptr;          //initially   two->next will be nptr if no twos
-======================================================================
        
/*
### Explanation of the Merging Process in the Optimal Solution

In the optimal solution, after segregating the nodes into three separate sublists (`0s`, `1s`, and `2s`), we merge them into a single sorted linked list.

#### Merging Logic
1. **Dummy Nodes Initialization:**
   - `zeroHead`, `oneHead`, and `twoHead` are dummy nodes used as placeholders for their respective sublists.
   - `zero`, `one`, and `two` pointers traverse and build their sublists.

2. **Connecting the Sublists:**
   - If the `1s` list is not empty:
     zero->next = oneHead->next;
   - Otherwise, connect the `0s` list directly to the `2s` list:
     zero->next = twoHead->next;
   - The `1s` list is always connected to the `2s` list:
     one->next = twoHead->next;
   
   - Terminate the final list explicitly:

     two->next = nullptr;
  

3. **Returning the Sorted List:**
   - The new head of the sorted list is:
     ```cpp
     return zeroHead->next;
     ```

#### Edge Cases
1. **Case 1: No `0s` in the List**
   - `zeroHead->next` will be `nullptr`.
   - `zero->next` connects to `oneHead->next` (if it exists) or `twoHead->next`.
   - Final structure:
     - Head points to the `1s` list if present, otherwise directly to the `2s` list.

2. **Case 2: No `1s` in the List**
   - `oneHead->next` will be `nullptr`.
   - `zero->next` connects directly to `twoHead->next`.
   - Final structure:
     - Head points to the `0s` list, followed by the `2s` list.

3. **Case 3: No `2s` in the List**
   - `twoHead->next` will be `nullptr`.
   - `zero->next` connects to `oneHead->next` (if it exists).
   - Final structure:
     - Head points to the `0s` list, followed by the `1s` list.

#### Visualization of Edge Cases

1. **No `0s` (Input: `1 -> 2 -> 1 -> 2`)**
   - `0s`: Empty (`zeroHead->next = nullptr`)
   - `1s`: `1 -> 1`
   - `2s`: `2 -> 2`
   - Merging:
     - `zero->next = oneHead->next`.
     - `one->next = twoHead->next`.
     - Result: `1 -> 1 -> 2 -> 2`.

2. **No `1s` (Input: `0 -> 2 -> 0 -> 2`)**
   - `0s`: `0 -> 0`
   - `1s`: Empty (`oneHead->next = nullptr`)
   - `2s`: `2 -> 2`
   - Merging:
     - `zero->next = twoHead->next`.
     - Result: `0 -> 0 -> 2 -> 2`.

3. **No `2s` (Input: `0 -> 1 -> 0 -> 1`)**
   - `0s`: `0 -> 0`
   - `1s`: `1 -> 1`
   - `2s`: Empty (`twoHead->next = nullptr`)
   - Merging:
     - `zero->next = oneHead->next`.
     - `one->next = twoHead->next`.
     - Result: `0 -> 0 -> 1 -> 1`.

*/

// Visualization of Edge Cases

// 1. No 0s (Input: 1 -> 2 -> 1 -> 2)
//    - 0s: Empty (zeroHead->next = nullptr)
//    - 1s: 1 -> 1
//    - 2s: 2 -> 2
//    - Merging:
//      - zero->next = oneHead->next.
//      - one->next = twoHead->next.
//      - Result: 1 -> 1 -> 2 -> 2.

// 2. No 1s (Input: 0 -> 0 -> 2 -> 2)
//    - 0s: 0 -> 0
//    - 1s: Empty (oneHead->next = nullptr)
//    - 2s: 2 -> 2
//    - Merging:
//      - zero->next = twoHead->next.
//      - one->next = nullptr (since no 1s).
//      - Result: 0 -> 0 -> 2 -> 2.

// 3. No 2s (Input: 0 -> 1 -> 0 -> 1)
//    - 0s: 0 -> 0
//    - 1s: 1 -> 1
//    - 2s: Empty (twoHead->next = nullptr)
//    - Merging:
//      - zero->next = oneHead->next.
//      - one->next = nullptr (since no 2s).
//      - Result: 0 -> 0 -> 1 -> 1.

// 4. All values are the same (Input: 1 -> 1 -> 1)
//    - 0s: Empty (zeroHead->next = nullptr)
//    - 1s: 1 -> 1 -> 1
//    - 2s: Empty (twoHead->next = nullptr)
//    - Merging:
//      - zero->next = oneHead->next.
//      - one->next = nullptr (since no 2s).
//      - Result: 1 -> 1 -> 1.

// 5. All values are distinct (Input: 0 -> 2 -> 1)
//    - 0s: 0
//    - 1s: 1
//    - 2s: 2
//    - Merging:
//      - zero->next = oneHead->next.
//      - one->next = twoHead->next.
//      - Result: 0 -> 1 -> 2.

// 6. Empty list (Input: Empty)
//    - 0s: Empty (zeroHead->next = nullptr)
//    - 1s: Empty (oneHead->next = nullptr)
//    - 2s: Empty (twoHead->next = nullptr)
//    - Merging:
//      - zero->next = nullptr (since no 0s).
//      - one->next = nullptr (since no 1s).
//      - two->next = nullptr (since no 2s).
//      - Result: Empty list.

