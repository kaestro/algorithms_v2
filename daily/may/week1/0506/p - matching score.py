import re

def solution(word:str, pages:[])->int:
    word = word.lower()
    max_score, max_idx = 0, 0
    page_scores = {}
    converted_pages = {}
    Link_cnt_idx, Links_idx, base_score_idx, link_score_idx = 0, 1, 2, 3
    for page in pages:
        page = page.lower()
        address = re.search("content=(\\\".+\")", page).group()[9:-1]
        links = re.findall("a href=\"(.+)\"", page)
        body = re.findall("<body>([\s\S]*?)</body>", page)
        body = re.sub('[^a-z]+', '.', '.'.join(body)).split('.')
        converted_pages[address] = [len(links), links, body.count(word), 0]
    
    for address, page in converted_pages.items():
        for link in page[Links_idx]:
            if link not in converted_pages: continue
            converted_pages[link][link_score_idx] += page[base_score_idx] / page[Link_cnt_idx]
    
    idx = 0
    for address, page in converted_pages.items():
        total_score = page[link_score_idx] + page[base_score_idx]
        if total_score > max_score:
            max_score = total_score
            max_idx = idx
        idx += 1
        
    return max_idx


if __name__ == "__main__":
    word = "Muzi"
    pages = ["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"]
    word = "blind"
    pages = ["<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"]
    solution(word, pages)
