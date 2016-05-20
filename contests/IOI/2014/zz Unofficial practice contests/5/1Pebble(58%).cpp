# left — turn 90 degrees to the left (counter clockwise) and remain in the current cell (e.g. if it was facing south before, then it will face east after the command).
# right — turn 90 degrees to the right (clockwise) and remain in the current cell (e.g. if it was facing west before, then it will face north after the command).
# move — move one unit forwards (in the direction the odometer is facing) into an adjacent cell. If no such cell exists (i.e. the border in that direction has been already reached) then this command has no effect.
# get — remove one pebble from the current cell. If the current cell has no pebbles, then the command has no effect.
# put — add one pebble to the current cell. If the current cell already contains 15 pebbles, then the command has no effect. The odometer never runs out of pebbles.
# halt — terminate the execution.

# L: (i.e. L followed by a colon ':') — declares the location within a program of a label L. All declared labels must be unique. Declaring a label has no effect on the odometer.
# jump L — continue the execution by unconditionally jumping to the line with label L.
# border L — continue the execution jumping to the line with label L, if the odometer is on a border facing the edge of the grid (i.e. a move instruction would have no effect); otherwise, the execution continues normally and this command has no effect.
# pebble L — continue the execution jumping to the line with label L, if the current cell contains at least one pebble; otherwise, the execution continues normally and this command has no effect.



[SUBTASK 1]  # ST 1

left
jump A

A:
pebble B
jump E

B:
get
right
right
move
jump A

E:
halt

[SUBTASK 2]   # ST 2

left
jump A

A:
pebble B
border E
jump J

B:
border C
jump D

C:
get
left
move
put
left
left
move
right
move
jump A

D:
get
right
move
put
left
left
move
left
move
jump A

E:
left
jump F

F:
move
pebble G
right
right
move
right
move
right
jump H

G:
get
right
right
move
put
right
right
jump F

H:
move
pebble I
right
right
move
left
move
left
jump Z

I:
get
right
right
move
put
right
right
jump H

J:
right
jump K

K:
move
pebble L
right
right
move
left
move
left
jump M

L:
get
right
right
move
put
right
right
jump K

M:
move
pebble N
right
right
move
right
move
right
jump Z

N:
get
right
right
move
put
right
right
jump M


Z:
halt

[SUBTASK 3]    # ST 3

right

A:
pebble B
move
jump A

B:
right
right
jump C

C:
right
right
get
move
pebble Z
put
jump D

D:
move
pebble C
jump D

Z:
halt

[SUBTASK 4]   # ST 4

right
right

A:          # // go to each row and start check
left
move
jump B

B:          # // check the row
pebble C
border D
move
jump B

C:          # // if a pebble is found collect it in the 0th column
get
right
right
jump G

D:          # // completed searching the row
right
right
jump E

E:           # // go to 0th column
move
border F
jump E

F:           # // at 0th column, check if it's border row, else go to next row
left
border P
move
jump A

G:           # // returning a pebble to the 0th column
move
border H
jump G

H:            # // at 0-th column to return a pebble
put
right
right
move
jump B

P:              # //done collecting all pebbles in 0th column
right
right
jump Q

Q:              # // returning after finishing column search
move
border R
jump Q

R:               # // time to start anew
right
right
move
jump S

S:                # // go search for a pebble
pebble T
border Z
move
jump S

T:
right
right
get
move
jump U

U:
border V
move
jump U

V:
put
right
right
move
jump S

Z:
halt

[SUBTASK 5]   # ST 5

Z:
halt
