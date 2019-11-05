import requests
from bs4 import BeautifulSoup

baseUrl="https://google.com/"
result=requests.get(baseUrl)
if(result.status_code==200):
    #print(result.status_code)
    #print(result.headers)
    src=result.content
    #print(src)
    soup = BeautifulSoup(src,'lxml')
    links = soup.find_all('a')
    print(links)
    print("\n")
    urls =[]
    for link in links:
        urls.append(link.attrs['href'])
        print(link)

    for x in urls:
        print(x)
        result_profiles=requests.get(baseUrl+x)
        if(result_profiles.status_code==200):
            #print(result_profiles.status_code)
            #print(result_profiles.headers)
            src_profile=result_profiles.content
            print(src_profile)
            soup = BeautifulSoup(src_profile,'lxml')
            
