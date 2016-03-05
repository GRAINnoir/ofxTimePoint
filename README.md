# ofxTimePoint

high resolution clock based on C++11 chrono library

.h

```
ofxTimePoint pt;
double timePoint;

```

.cpp

```
pt.startPoint(NANO);
// monitored process
...
timePoint = pt.getTimePoint();
```