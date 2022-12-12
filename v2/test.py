import requests
from bs4 import BeautifulSoup
import pprint
import json
import time
import datetime

file_path1 = "./hre_data.json"
file_path2 = "./step_problem_id_data.json"
file_path3 = "./user_data.json"
url = 'https://www.acmicpc.net'
users_info = [
    {
        "id": "mekind",
        "total": 0,
        "detail": [],
        "pid": []
    },
    {
        "id": "gksrudtn99",
        "total": 0,
        "detail": [],
        "pid": []
    },
    {
        "id": "mikle8244",
        "total": 0,
        "detail": [],
        "pid": []
    }
]
step_infos = []  # 단계 url(숫자가 연속되지 않아서 파싱함)


def get_step_info():
    print("get_step_info")
    response = requests.get(url+'/step')
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')
    # print(soup.prettify())
    cnt = 1
    for link in soup.tbody.find_all('a'):
        # print(link)
        now_info = {
            "step_id": cnt,
            "description": link.string,
            "herf": link.get('href')
        }
        step_infos.append(now_info)
        cnt += 1
    with open(file_path1, 'w') as outfile:
        json.dump(step_infos, outfile)


def get_problem_count_and_id():
    print("get_problem_count_and_id")
    total_cnt = 0
    for info in step_infos:
        response = requests.get(url+info['herf'])
        html = response.text
        soup = BeautifulSoup(html, 'html.parser')
        info['problem_ids'] = []
        for link in soup.tbody.find_all('td', class_='list_problem_id'):
            info['problem_ids'].append(link.string)
        info['problem_count'] = len(info['problem_ids'])
        total_cnt += info['problem_count']
        time.sleep(2)

    with open(file_path2, 'w') as outfile:
        json.dump(step_infos, outfile)


def get_users_status(match_count):
    for info in users_info:
        print(f"now : {info['id']}")
        response = requests.get(url+f'/user/{info["id"]}')
        html = response.text
        soup = BeautifulSoup(html, 'html.parser')
        a = soup.find_all('div', class_='problem-list')[0]
        details = {}
        for link in a.find_all('a'):
            now = int(link.string)
            info['pid'].append(now)
            # print(now)
            # print(match_count.get(now))
            if match_count.get(now) is not None:
                info['total'] += 1
                if now == 10816 or now == 14425:
                    info['total'] += 1

                if details.get(match_count[now]) is not None:
                    details[match_count[now]]['count'] += 1
                else:
                    details[match_count[now]] = {
                        'id': step_infos[match_count[now]-1]['step_id'],
                        'description': step_infos[match_count[now]-1]['description'],
                        'count': 1,
                        'total': step_infos[match_count[now]-1]['problem_count']
                    }
        info['details'] = details


if __name__ == "__main__":
    try:
        with open(file_path1, "r") as json_file:
            step_infos = json.load(json_file)
    except:
        get_step_info()

    try:
        with open(file_path2, "r") as json_file:
            step_infos = json.load(json_file)
    except:
        get_problem_count_and_id()

    total_cnt = 0
    match_count = {}

    for info in step_infos:
        for num in info['problem_ids']:
            now = int(num)
            match_count[now] = info['step_id']
        total_cnt += info['problem_count']
        # print(len(info['problem_ids']) == info['problem_count'])
    # print(total_cnt)
    # total_cnt = 398

    match_count = dict(sorted(match_count.items()))
    '''
    중복되는 문제 발생
    10816번 13
    14425번 13
    '''
    # print(len(step_infos))
    get_users_status(match_count)
    print(datetime.datetime.now())
    print("================Brief=================")
    for user in users_info:
        print(f"\n아이디: {user['id']}  현황 : {user['total']} / {total_cnt}")

    print("\n================Detail=================")
    for user in users_info:
        print(f"\n=============아이디: {user['id']}=============\n")
        n_details = user['details']
        n_details = dict(sorted(n_details.items()))
        # print(n_details)
        for i in range(1, 55):
            if n_details.get(i) is None:
                print(
                    f"{step_infos[i-1]['step_id']}. {step_infos[i-1]['description']}:  ( 0 / {step_infos[i-1]['problem_count']})")
            else:
                print(
                    f"{n_details[i]['id']}. {n_details[i]['description']}:  ( {n_details[i]['count']} / {n_details[i]['total']})")
        print("\n=============End=============\n")
