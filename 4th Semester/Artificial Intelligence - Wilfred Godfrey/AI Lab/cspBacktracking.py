# Define the variables and their domains
variables = ['A', 'B', 'C', 'D']
domains = {
    'A': [1, 2, 3],
    'B': [1, 2,3],
    'C': [1, 2, 3],
    'D': [1, 2, 3]
}

# Define the constraints
constraints = [
    ('A', 'B', lambda a, b: a != b),
    ('B', 'C', lambda b, c: b != c),
    ('C', 'D', lambda c, d: c != d),
    ('A', 'D', lambda a, d: a != d)
]

# Define the backtracking function


def backtrack(assignment):
    if len(assignment) == len(variables):
        return assignment
    variable = select_unassigned_variable(assignment)
    for value in order_domain_values(variable, assignment):
        if is_consistent(variable, value, assignment):
            assignment[variable] = value
            result = backtrack(assignment)
            if result is not None:
                return result
            del assignment[variable]
    return None

# Define the helper functions


def select_unassigned_variable(assignment):
    for variable in variables:
        if variable not in assignment:
            return variable


def order_domain_values(variable, assignment):
    return domains[variable]


def is_consistent(variable, value, assignment):
    for v, w, constraint in constraints:
        if v == variable and w in assignment:
            if not constraint(value, assignment[w]):
                return False
        elif w == variable and v in assignment:
            if not constraint(assignment[v], value):
                return False
    return True


# Call the backtracking function and print the result
result = backtrack({})
if result is None:
    print("No solution found.")
else:
    print(result)
