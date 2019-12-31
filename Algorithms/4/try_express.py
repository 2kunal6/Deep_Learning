import math


def all_pair_short_path(dis_speed, s, i, j):
    for k in range(s):
        dis_speed[i][j] = min(dis_speed[i][j], dis_speed[i][k] + dis_speed[k][j])
    return dis_speed


def all_pair_short_path_first(arr, dis, dis_speed, s):
    for k in range(s):
        for i in range(s):
            for j in range(s):
                if (dis_speed[i][k] + dis_speed[k][j]) < dis_speed[i][j]:
                    if (dis[i][k] + dis[k][j]) <= arr[i][0] and arr[i][1] >= arr[k][1]:
                        dis[i][j] = dis[i][k] + dis[k][j]
                        dis_speed[i][j] = dis[i][j] * (1 / arr[i][1])
                    elif dis[i][k] + dis[k][j] <= arr[i][0] + arr[k][0]:
                        dis[i][j] = dis[i][k] + dis[k][j]
                        dis_speed[i][j] = dis_speed[i][k] + dis_speed[k][j]
    return (dis, dis_speed)


def main():
    n = input()
    temp = [int(arg) for arg in n.strip().split()]
    s = temp[0]
    d = temp[1]
    arr = [[] * 2 for x in range(s)]
    for i in range(s):
        n = input()
        arr[i] = [int(arg) for arg in n.strip().split()]

    #print(arr)

    dis = [[0] * s for x in range(s)]
    dis_speed = [[0] * s for x in range(s)]
    for i in range(s):
        n = input()
        lst = [arg for arg in n.strip().split()]
        for j in range(s):
            if lst[j] == "−1" or lst[j] == "-1":
                dis[i][j] = math.inf
                dis_speed[i][j] = math.inf
            else:
                if int(lst[j]) <= arr[i][0]:
                    dis[i][j] = int(lst[j])
                    dis_speed[i][j] = int(lst[j]) * (1 / arr[i][1])
                else:
                    dis[i][j] = math.inf
                    dis_speed[i][j] = math.inf

    delv = [[0] * 2 for x in range(d)]
    for i in range(d):
        n = input()
        delv[i] = ([int(arg) for arg in n.strip().split()])

    dis, dis_speed = all_pair_short_path_first(arr, dis, dis_speed, s)

    for i in range(d):
        start = delv[i][0] - 1
        end = delv[i][1] - 1
        dis_speed = all_pair_short_path(dis_speed, s, start, end)
        # print(".2f"%dis_speed[start][end], end=" ")
        print(round(dis_speed[start][end],2), end=" ")
        # print(dis_speed[start][end], end=" ")


main()
