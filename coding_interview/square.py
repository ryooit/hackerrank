# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # write your code in Python 3.6
    countries={}
    country_count=0
    for i in range(len(A)):
        for j in range(len(A[0])):
            # target square
            square=A[i][j]
            state=(i,j)
            # west square
            w_square=A[i][j-1]
            w_state=(i,j-1)
            # north square
            n_square=A[i-1][j]
            n_state=(i-1,j)
            if(i==0 and j==0): # edge case
                country_count+=1
                countries[state]=country_count
            elif(i==0):
                if(square==w_square):
                    countries[state]=country_count
                else:
                    country_count+=1
                    countries[state]=country_count
            elif(j==0):
                if(square==n_square):
                    countries[state]=country_count
                else:
                    country_count+=1
                    countries[state]=country_count
            else:
                if(square==w_square and square==n_square):
                    small=min(countries[w_state],countries[n_state])
                    big=max(countries[w_state],countries[n_state])
                    for country in countries:
                        if(countries[country]==big):
                            countries[country]=small
                    countries[state]=small
                elif(square==w_square):
                    countries[state]=countries[w_state]
                elif(square==n_square):
                    countries[state]=countries[n_state]
                else:
                    country_count+=1
                    countries[state]=country_count

    # count distinct value
    set_of_countries=set()
    for country in countries:
        set_of_countries.add(countries[country])

    return(len(set_of_countries))
