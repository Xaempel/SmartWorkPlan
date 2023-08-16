[Home](../README.md)
# RoadMap
## Reference 

[Coming Feature](#coming-feature)

[Improvement](#improvement)

## Legend for RoadMap

    X means that the function has not been implemented yet
    # means that the function has been implemented

## Coming Feature
[Return](#reference)

* Shift Feature

| Goal      |Description| Status    |
| --------- | --------- | --------- |
|  Create a calendar widget         | integrates the calendar widget with the mainwindow class | # |
|  Create a basic function for adding employees to a shift system | create a function that will add the employee to the day and then save the relevant data | # |
| Create a delete function for shift system | create a function that will delete the employee and then delete the data related to the employee | # |
| Create a function that will respond to the removal of a given employee and calls the removal function | the function is must to react to the removal of a given worker and adapt the calendar to this action | X |

* Worker Feature

| Goal      |Description| Status    |
| --------- | --------- | --------- |
| Create add worker system          | system must add worker to layout and add information on worker for file           | # | 
| Create delete worker system       | system must delete worker on  mainwindow layout and delete information on worker in file           | # |  
| Create info widget for worker     | this widget must present info for worker name surname work hours etc          | X |


* Other things

| Goal      |Description| Status    |
| --------- | --------- | --------- |
| Create a better and smoother ui   | I don't have any big ideas yet, I'll add them in future commits | X | 
| Divide the main window into pages | See Qt creator menu style not 100% but it's a good starting point | X |  
| Create a App Icon | the icon must be a strawberry this is not a raspberry pi reference this my preferention i love strawberries  | X |

# Improvement
[Return](#reference)

| Goal      |Description| Status    |
| --------- | --------- | --------- |
| Change the worker model class to be more compatible with the VMC architecture | The problem is to attach the employee widget class to the worker model class, a possible solution is to explicitly declare the employee widget constructor          | # |
