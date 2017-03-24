vector<int> v;
vector<ll> tree;

void increase(int i, int delta)
{
    for (; i < (int)tree.size(); i |= i + 1)
        tree[i] += delta;
}

int sum(int i)
{
	int ans = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		ans += tree[i];
	return ans;
}

int getsum(int left, int right)
{
    return sum(right) - sum(left-1);
}

void constuct()
{
    for(int i = 0 ; i<tree.size(); i++)
        increase(i, v[i]);
}
