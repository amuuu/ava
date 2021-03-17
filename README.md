# Ava Sound Engine
A more complete documentation will be added soon.

You can see the implemetation kanban board in the repo's [projects section](https://github.com/funktional-stdo/ava/projects).


## Build Ava (+ Demo Programs)
To build the engine alongside with the demo program you just need to make the project inside the root directory using the command below:
```
make
```

Then you can run the demo programs using this command:
```
# for the simple demo
./demo_simple/AvaSimpleDemo

# for the structured demo
./demo_structured/AvaStructuredDemo
```

If you configure the CMake scripts, you might need to use the command below to update the auto-generated makefiles (in the root directory). Then build the project using the previous instructions.
```
make --configure .
```
