class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m)
    {
        int temp1 = n;
        int temp2 = m;
        Node* towork = head;
        while(towork!=NULL && towork->next!=NULL)
        {
            while(towork!=NULL && m>1)
            {
                towork = towork->next;
                m-=1;
            }
            if(towork==NULL)
            {
                continue;
            }
            Node* toskip = towork->next;
            while(toskip!=NULL && n>0)
            {
                toskip = toskip->next;
                n-=1;
            }
            towork->next = toskip;
            towork = toskip;
            n = temp1;
            m = temp2;
        }
        return head;
    }
};