#include <iostream>

struct ListNode
{
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) { }
   ListNode(int x) : val(x), next(nullptr) { }
   ListNode(int x, ListNode* next) : val(x), next(next) { }
};

class Solution
{
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
   {
      ListNode* ans = new ListNode;
      ListNode* traversalNode1 = l1;
      ListNode* traversalNode2 = l2;
      ListNode* ansTraversal = ans;
      bool carryFlag{false};


      ansTraversal = ans;
      // iterate through the lists concurrently, even if the other one is null
      while (traversalNode1 != nullptr || traversalNode2 != nullptr)
      {
         // check for which turned null, then make sure to add leading 0 to keep up with concurrency of the other list
         if (traversalNode1 == nullptr) { traversalNode1 = new ListNode(0); } // redundancy from constructor, but for the sake of straightforward
         if (traversalNode2 == nullptr) { traversalNode2 = new ListNode(0); }

         // std::cout << traversalNode1->val << " + " << traversalNode2->val << " = ";
         ansTraversal->val = traversalNode1->val + traversalNode2->val;

         if (carryFlag)
         {
            ++ansTraversal->val;
            carryFlag = false;
         }

         // std::cout << ansTraversal->val << "::" << ans->val << "\n";
         if (ansTraversal->val >= 10)
         {
            ansTraversal->val = ansTraversal->val % 10; // maybe minus 10 is faster?
            carryFlag = true;
         }

         // only create a new next node if there is size continuation in either l1 or l2
         if (traversalNode1->next != nullptr || traversalNode2->next != nullptr) { ansTraversal->next = new ListNode; }
         else if (carryFlag) { ansTraversal->next = new ListNode(1); carryFlag = false; } // if the above cannot continue, make sure carry flag is checked in case hanging 1

         traversalNode1 = traversalNode1->next;
         traversalNode2 = traversalNode2->next;
         ansTraversal = ansTraversal->next;
      }


      // std::cout << "|||" << ansTraversal->val << "\n";
      // // if carry flag is true by the end, add final 1 to the list
      // if (carryFlag) { ansTraversal = new ListNode(1); }




      // //debug ans
      // ansTraversal = ans;
      // std::cout << "[";
      // while (ansTraversal != nullptr)
      // {
      //    std::cout << ansTraversal->val;

      //    if (ansTraversal->next != nullptr) { std::cout << ","; }

      //    ansTraversal = ansTraversal->next;
      // }
      // std::cout << "]";

      return ans;

      // ListNode* traversalNode;
      // traversalNode = l1;

      // while (traversalNode != nullptr)
      // {
      //    std::cout << traversalNode->val;
      //    traversalNode = traversalNode->next;
      // }

      // std::cout << "\n";

      // traversalNode = l2;
      // while (traversalNode != nullptr)
      // {
      //    std::cout << traversalNode->val;
      //    traversalNode = traversalNode->next;
      // }

   }
};

int main()
{
   ListNode* l1{new ListNode};
   ListNode* l2{new ListNode};

   l1->val = 9;
   l1->next = new ListNode(9);
   l1->next->next = new ListNode(9);
   l1->next->next->next = new ListNode(9);
   l1->next->next->next->next = new ListNode(9);
   l1->next->next->next->next->next = new ListNode(9);
   l1->next->next->next->next->next->next = new ListNode(9);

   l2->val = 9;
   l2->next = new ListNode(9);
   l2->next->next = new ListNode(9);
   l2->next->next->next = new ListNode(9);

   Solution solution;
   solution.addTwoNumbers(l1, l2);

   return 0;
}