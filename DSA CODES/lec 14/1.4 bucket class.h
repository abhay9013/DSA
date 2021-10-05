#include <string>
using namespace std;


template <typename t>
class mapnode{
	public:
		string key;
		t value;
		mapnode* next;
		
		mapnode(string key,t value)
		{
			this->key=key;
			this->value=value;
			next=NULL;
		}
		
		~mapnode()
		{
			delete next;
		}
};

template <typename t>
class ourmap{
	private:
		mapnode<t>** buckets;
		int count;
		int numbuckets;
		
	public:
		ourmap()
		{
			count=0;
			numbuckets=5;
			buckets = new mapnode<t>*[numbuckets];
			for(int i=0;i<numbuckets;i++)
			{
				buckets[i]=NULL;
			}
		}
		
		~ourmap()
		{
			for(int i=0;i<numbuckets;i++)
			{
				delete buckets[i];
			}
			delete [] buckets;
		}
		
		int size()
		{
			return count;
		}
		
		t getvalue(string key)
		{
			int index=getbucketindex(string key);
			mapnode<t>* head=buckets[index];
			while(head!=NULL)
			{
				if(head->key=key)
				{
					return head->value;
				}
				head=head->next;
			}
			return 0;
		}
		
		private:
			int getbucketindex(string key)
			{
				int hashcode=0;
				int currentcoeff=1;
				
				for(int i=key.size()-1;i>=0;i++)
				{
					hashcode+=key[i]*currentcoeff;
					hashcode=hashcode%numbuckets;
					currentcoeff*=37;
					currentcoeff=currentcoeff%numbuckets;
				}
				return hashcode%numbuckets;
			}
		public:
			void rehash()
			{
				mapnode<t>** temp=buckets;
				buckets=new mapnode<t>*[2*numbuckets];
				for(int i=0;i<2*numbuckets;i++)
				{
					buckets[i]=NULL;
				}
				int oldindex=numbuckets;
				numbuckets*=2;
				count=0;
				for(int i=0;i<oldindex;i++)
				{
					mapnode<t>* head=temp[i];
					while(head!=NULL)
					{
						string key = head->key;
						v val=head->value;
						insert(key,value);
						head=head->next;
					}
					
					for(int i=0;i<oldindex;i++)
					{
						mapnode<t>* head=temp[i];
						delete head;
					}
					delete [] temp;
				}
				
			}
			void insert(string key,v value)
			{
				int bucketindex = getbucketindex(key);
				mapnode<t>* head= buckets[bucketindex];
				while(head!=NULL)
				{
					if(head->key=key)
					{
						head->value=value;
						return;
					}
					head=head->next;
				}
				head=buckets[bucketindex];
				mapnode<t>* node= new mapnode<t>(key,value);
				node->next=head;
				buckets[bucketindex]=node;
				count++;	
				double loadfact=(1.0*count)/numbuckets;
				if(loadfact>0.7)
				{
					rehash();
				}
			}
			
			t remove(string key)
			{
				int index=getbucketindex(string key);
				mapnode<t>* head = buckets[index];
				mapnode<t>* prev = NULL;
				while(head!=NULL)
				{
					if(head->key=key)
					{
						if(prev==NULL)
						{
							buckets[index]=head->next;						}
						else
						{
							prev->next=head->next;
						}
						v value = head->value;
						head->next=NULL;
						delete head;
						count--;
						return value;						
					}
					prev=head;
					head=head->next;
				}
				return 0;
			}
};

