void split (Node* &in, Node*& odds, Node*& evens)
{
    if(in==NULL)
    {
        return;
    }
    split(in->next, odds, evens);
    if(abs(in->value%2)==1)
    {
        in->next = odds;
        odds = in;
        in = NULL;
    }
    else
    {
        in ->next = evens;
        evens = in;
        in = NULL;
    }
}