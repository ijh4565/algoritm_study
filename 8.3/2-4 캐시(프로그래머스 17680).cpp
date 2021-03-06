//https://programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;
  deque<string> cache; //캐시 생성
  
  for(int i = 0; i < cities.size(); i++){
  
    string city = cities.at(i); //스트링 저장
    bool hit = false; //힛인지 아닌지
    int index = 0;    
    
    for(int j = 0; j < city.length(); j++){ //전부 소문자로
      city[j] = tolower(city[j]);
    }
    
    for(int k = 0; k < cache.size(); k++){
      if(cache[k] == city){//캐시 힛
        hit = true;
        index = k;
        break;
      }
    }
    
    cache.push_back(city); //캐시가 힛이던 아니던 무조건 cache는 넣어야 함
    
    if(hit == true){//힛
      cache.erase(cache.begin() + index);
      answer += 1;
    }
    else{//미스
      if(cache.size() > cacheSize) cache.pop_front();
      answer += 5;
    }
  }
  return answer;
}
