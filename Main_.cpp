#include<iostream>
#include<string>
// #include"node.h"
#include"HuffmanCoding.h"
#include"HuffmanDecoding.h"
using namespace std;

void data(string s, string encode, string treeString){
    cout<<"Statistics:"<<endl;
    int treeSize=0;
    for(char&c:treeString){
        if(c=='0' || c=='1')    treeSize+=1;
        else                    treeSize+=8;
    }
    cout<<"original string size:\t"<<s.length()*8<<" bits"<<endl;
    cout<<"encode size:\t\t"<<encode.length()<<" bits"<<endl;
    cout<<"tree size:\t\t"<<treeSize<<" bits"<<endl;
    cout<<"memory saved:\t\t"<<100-((encode.length()+treeSize)*100/(s.length()*8))<<"%"<<endl;
    cout<<endl;
}

int main()
{
    string s;
    cout<<"enter string: "<<endl;
    // cin>>s;
    getline(cin, s);

    // generating huffman code
    auto p = HuffmanCode(s);
    string treeString = p.first, encode = p.second;
    cout<<"Encode:\n"<<encode<<endl<<endl;
    cout<<"Tree String:\n"<<treeString<<endl<<endl;

    // data showing
    data(s, encode, treeString);#include<iostream>
#include<string>
// #include"node.h"
#include"HuffmanCoding.h"
#include"HuffmanDecoding.h"
using namespace std;

void data(string s, string encode, string treeString){
    cout<<"Statistics:"<<endl;
    int treeSize=0;
    for(char&c:treeString){
        if(c=='0' || c=='1')    treeSize+=1;
        else                    treeSize+=8;
    }
    cout<<"original string size:\t"<<s.length()*8<<" bits"<<endl;
    cout<<"encode size:\t\t"<<encode.length()<<" bits"<<endl;
    cout<<"tree size:\t\t"<<treeSize<<" bits"<<endl;
    cout<<"memory saved:\t\t"<<100-((encode.length()+treeSize)*100/(s.length()*8))<<"%"<<endl;
    cout<<endl;
}

int main()
{
    string s;
    cout<<"enter string: "<<endl;
    // cin>>s;
    getline(cin, s);

    // generating huffman code
    auto p = HuffmanCode(s);
    string treeString = p.first, encode = p.second;
    cout<<"Encode:\n"<<encode<<endl<<endl;
    cout<<"Tree String:\n"<<treeString<<endl<<endl;

    // data showing
    data(s, encode, treeString);

    cout<<"Decode:"<<endl;
    string decoded = Decode(encode, treeString);
    cout<<decoded<<endl;
}

// INDIA is my country. Every Indians are my Brothers & Sisters
// Hi, I am Jainish Patel. I don't know what should I do @

/*
It was a cold Friday evening on November 22, 2024, when Sarah received a notification on her phone: 'Reminder: Doctor's appointment at 3:30 PM tomorrow.' She sighed, knowing it had been a long week of meetings, coding, and endless emails. Earlier that day, she had spent hours debugging a Python script that kept throwing a ValueError because of an unexpected input type. 'Maybe I should have used TypeScript instead,' she thought. Her inbox was flooded with emails from various departments – Marketing, Sales, HR – each needing something urgent. Sarah couldn't help but notice the subject line of one email: 'URGENT: Update the company's website!' It was from her boss, who wanted the landing page to be redesigned with a new CSS framework called Tailwind. At the same time, a Slack message popped up on her laptop: 'Don't forget to push the latest changes to GitHub before the end of the day!' As if things couldn't get any more chaotic, her dog started barking, reminding her that it was time for his walk. She quickly sent a message to her colleague: 'I'll push the changes after dinner. Shouldn’t take long, just adding some new endpoints to the API.' Finally, she grabbed her coat, put on her headphones, and headed out the door, hoping to clear her mind. Walking through the park, she thought about her weekend plans: brunch with friends, a trip to the bookstore, and maybe even finishing that novel she'd been reading, 'The Hitchhiker's Guide to the Galaxy.' As she strolled along, she made a mental note to check her calendar for upcoming deadlines, including the final submission for her AI project on December 5th. After all, she had promised to include detailed charts, performance metrics, and predictions using the latest machine learning models. With so much on her plate, she couldn't afford to fall behind!
*/

    cout<<"Decode:"<<endl;
    string decoded = Decode(encode, treeString);
    cout<<decoded<<endl;
}

// INDIA is my country. Every Indians are my Brothers & Sisters
// Hi, I am Jainish Patel. I don't know what should I do @

/*
It was a cold Friday evening on November 22, 2024, when Sarah received a notification on her phone: 'Reminder: Doctor's appointment at 3:30 PM tomorrow.' She sighed, knowing it had been a long week of meetings, coding, and endless emails. Earlier that day, she had spent hours debugging a Python script that kept throwing a ValueError because of an unexpected input type. 'Maybe I should have used TypeScript instead,' she thought. Her inbox was flooded with emails from various departments – Marketing, Sales, HR – each needing something urgent. Sarah couldn't help but notice the subject line of one email: 'URGENT: Update the company's website!' It was from her boss, who wanted the landing page to be redesigned with a new CSS framework called Tailwind. At the same time, a Slack message popped up on her laptop: 'Don't forget to push the latest changes to GitHub before the end of the day!' As if things couldn't get any more chaotic, her dog started barking, reminding her that it was time for his walk. She quickly sent a message to her colleague: 'I'll push the changes after dinner. Shouldn’t take long, just adding some new endpoints to the API.' Finally, she grabbed her coat, put on her headphones, and headed out the door, hoping to clear her mind. Walking through the park, she thought about her weekend plans: brunch with friends, a trip to the bookstore, and maybe even finishing that novel she'd been reading, 'The Hitchhiker's Guide to the Galaxy.' As she strolled along, she made a mental note to check her calendar for upcoming deadlines, including the final submission for her AI project on December 5th. After all, she had promised to include detailed charts, performance metrics, and predictions using the latest machine learning models. With so much on her plate, she couldn't afford to fall behind!
*/
