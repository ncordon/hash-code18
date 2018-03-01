#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> position;

struct Ride {
  int id;
  position start;
  position end;
  long long t_start;
  long long t_end;
};

int operator-(position& a, position& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

class ride_comparison{
public:
  bool operator()(Ride& a, Ride& b){
    return a.t_start > b.t_start;
  }
};


int score(position car, Ride r, long long step, int bonus) {
  bool would_start = step + (car - r.start) <= r.t_start;
  int would_end = (car - r.start) + (r.start - r.end);
  int diff = r.t_end - would_end;

  if (diff > 0)
    return would_start * bonus + (r.start - r.end);
  else
    return 0;
}

void print_solution(vector<list<int> >& solution) {
  for(auto& rides : solution){
    cout << rides.size() << " ";
    copy(rides.begin(), rides.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}

int main() {
  int R, C, F, N, B;
  long long T;
  cin >> R >> C >> F >> N >> B >> T;
  priority_queue<Ride, vector<Ride>, ride_comparison> rides;
  vector<bool> rides_used(N, false);
  vector<int> steps_remaining(F, 0);
  vector<position> vehicle_position(F, {0,0});
  vector<bool> vehicle_used(F, false);
  // ride_assigned to a certain vehicle at a certain time
  vector<Ride> vehicle_ride(F);
  // rides assigned to each vehicle
  vector<list<int> > solution(F);

       
  for (int i = 0; i < N; i++) {
    Ride current;
    current.id = i;
    
    cin >> current.start.first >> current.start.second >> current.end.first >> current.end.second
        >> current.t_start >> current.t_end;

    rides.push(current);
  }

  for (long long t = 0; t < T; t++) {
    vector<Ride> discarded;
    // v = vehicle
    // decrease remaining time to end if vehicle v if it is being used
    for (int v = 0; v < F; v++) {
      if(vehicle_used[v] && t >= vehicle_ride[v].t_start) {
        if(steps_remaining[v] > 0){
          steps_remaining[v]--;
          
          if(steps_remaining[v] == 0){
            vehicle_used[v] = false;
            vehicle_position[v] = vehicle_ride[v].end;
          }
        }
      }
    }


    bool can_assign = true;
    
    while(!rides.empty() && can_assign){
      Ride current_ride = rides.top();
      rides.pop();
      can_assign = false;
      
      if(!rides_used[current_ride.id]) {
        int closest = -1;
        int max_score = numeric_limits<int>::min();
      
        for(int v = 0; v < F; v++) {
          if(!vehicle_used[v]){
            int v_score = score(vehicle_position[v], current_ride, t, B);

            if(v_score > max_score && v_score > 0){
              can_assign = true;
              closest = v;
              max_score = v_score;
            }
          }
        }

        if(can_assign) {
          vehicle_ride[closest] = current_ride;
          vehicle_used[closest] = true;
          steps_remaining[closest] = current_ride.end - vehicle_position[closest];
          solution[closest].push_back(current_ride.id);
          rides_used[current_ride.id] = true;
        } else if (current_ride.t_end > t) {
          discarded.push_back(current_ride);
        } 
      }
      // Re-evaluate if any car would be able to finish this ride
      /*
     if(!can_assign) {
        if(rides.t_

      }
      */
    }

    for (Ride& x : discarded) {
      rides.push(x);
    }
  }


  print_solution(solution);
  
}
