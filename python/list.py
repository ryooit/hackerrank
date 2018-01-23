nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 'n' for each 'n' in nums
# basic
my_list = []
for n in nums:
    my_list.append(n)
print(my_list)

# list comprehension
my_list = [n for n in nums]
print(my_list)

# 'n * n' for each 'n' in nums
# basic
my_list = []
for n in nums:
    my_list.append(n*n)
print(my_list)

# list comprehension
my_list = [n*n for n in nums]
print(my_list)
 
# map + lambda
my_list = map(lambda n: n*n, nums)
print(list(my_list))

# 'n' for each 'n' in nums if 'n' is even
# basic
my_list = []
for n in nums:
    if (n%2 == 0):
        my_list.append(n)
print(my_list)

# list comprehension
my_list = [n for n in nums if n%2 == 0]
print(my_list)

# filter + lambda
my_list = filter(lambda n: n%2 == 0, nums)
print(list(my_list))

# (letter, num) pair for each letter in 'abcd' and each number in '0123'
# basic
my_list = []
for letter in 'abcd':
    for num in range(4):
        my_list.append((letter, num))
print(my_list)

# list comprehension
my_list = [(letter, num) for letter in 'abcd' for num in range(4)]
print(my_list)



# zip function
names = ['Bruce', 'Clark', 'Peter', 'Logan', 'Wade']
heros = ['Batman', 'Superman', 'Spiderman', 'Wolverine', 'Deadpool']
print(list(zip(names, heros)))

# a dict {'name' : 'hero'} for each name, hero in zip(names, heros)
# basic
my_dict = {}
for name, hero in zip(names, heros):
    my_dict[name] = hero
print(my_dict)

# dictionary comprehension
my_dict = {name: hero for name, hero in zip(names, heros)}
print(my_dict)

# if name not equal to Peter
my_dict = {name: hero for name, hero in zip(names, heros) if name != 'Peter'}
print(my_dict)



nums = [1, 1, 2, 1, 3, 4, 3, 4, 5, 5, 6, 7, 8, 7, 9, 9]
# basic
my_set = set()
for n in nums:
    my_set.add(n)
print(my_set)

# set comprehension
my_set = {n for n in nums}
print(my_set)


# yield 'n*n' for each n in nums
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# basic
def get_func(nums):
    for n in nums:
        yield n*n

my_gen = get_func(nums)

for i in my_gen:
    print(i)

# generator expression
my_gen = (n*n for n in nums)

for i in my_gen:
    print(i)
