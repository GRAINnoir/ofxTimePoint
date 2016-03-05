# ofxTimePoint

high resolution clock based on C++11 chrono library

usage:

```
ofxTimePoint pt;
double timePoint;

pt.startPoint(NANO);
// monitored process
...
timePoint = pt.getTimePoint();
```