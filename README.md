<h1 align="center">Object Pool Design Pattern in C++</h1>

<p align="center">
This C++ codebase implements the Object Pool design pattern, which is essential for managing the reuse of objects efficiently, improving performance, and reducing the overhead of object creation and destruction.
</p>

## Table of Contents
- [Introduction](#introduction)
- [Object Class](#object-class)
- [ObjectPool Class](#objectpool-class)
  - [Private Members](#private-members)
  - [Public Methods](#public-methods)
- [Usage](#usage)

## Introduction
The Object Pool design pattern is utilized to pool objects for reuse rather than creating and destroying them repeatedly. This approach significantly enhances performance and resource utilization, especially for costly object operations.

## Object Class
### Overview
The `Object` class symbolizes the entities managed within the pool. It contains a method named `DoSomething` to demonstrate an object performing an operation, outputting a simple message.

## ObjectPool Class
### Private Members
- `std::vector<std::shared_ptr<Object>> pool;`: Holds the pooled objects using smart pointers (`std::shared_ptr`) for automatic memory management.
- `int maxSize;`: Defines the pool's maximum capacity, limiting the number of objects it can contain concurrently.

### Public Methods
- **Constructor (`ObjectPool(int size)`):** Initializes the pool with a predetermined size, pre-filling it with `Object` instances for immediate use.
- **acquiredObject():** Retrieves an object from the pool, creating a new one if the pool is depleted.
- **releaseObject(std::shared_ptr<Object> obj):** Returns an object to the pool, ensuring it does not exceed its maximum capacity.

## Usage
```cpp
ObjectPool pool(3); // Create a pool with 3 objects
auto obj1 = pool.acquiredObject();
auto obj2 = pool.acquiredObject();
auto obj3 = pool.acquiredObject();
auto obj4 = pool.acquiredObject(); // Creates a new object as the pool is empty

pool.releaseObject(obj1);
pool.releaseObject(obj2);
pool.releaseObject(obj3);
// Attempt to release obj4 (optional based on logic)
