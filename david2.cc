#include <bits/stdc++.h>
using namespace std;

typedef unsigned U;
typedef pair<U, U> position;

struct Ride {
  position start;
  position end;
  U t_start;
  U t_end;
};

U operator-(position& a, position& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

U would_score(position car, Ride r, U step, U bonus) {
  bool would_start = step + (car - r.start) <= r.t_start;
  U would_end = (car - r.start) + (r.start - r.end);
  U diff = r.t_end - would_end;

  if (diff > 0)
    return would_start * bonus + (r.start - r.end);
  else
    return 0;
}

U main() {
  U R, C, F, N, B, T;
  cin >> R >> C >> F >> N >> B >> T;
  vector<Ride> rides(N);
  vector<bool> rided_used(F, false);
  vector<position> vehicle_position(F);
  vector<bool> vehicle_used(F, false);
  // ride_assigned to a certain vehicle at a certain time
  vector<Ride> vehicle_ride(F);
  // rides assigned to each vehicle
  vector<list<U> > solution(F);
  
  for (U i = 0; i < N; i++) {
    Ride current;

    cin >> current.start.first >> current.start.second >> current.end.first >> current.end.second
        >> current.t_start >> current.t_end;

    rides.push_back(current);
  }

  for (U i = 0; i < T; i++) {
    // v = vehicle
    // free v vehicle if it is being used
    for (U v = 0; v < F; v++) {
      if(vehicle_used[v]) {
        if(vehicle_position[v] - vehicle_ride[v].end == 1){
          vehicle_used[v] = false;
        }
      }
    }


    // assign rides to free vehicles


    
  }
}
