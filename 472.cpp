// Runtime: 1216 ms, faster than 5.05% of C++ online submissions for Concatenated Words.
// Memory Usage: 736.9 MB, less than 16.67% of C++ online submissions for Concatenated Words.
// TODO: find a faster solution

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Trie
{
public:
  vector<Trie *> x;
  bool hasWord = false;
  /** Initialize your data structure here. */
  Trie()
  {
    x = vector<Trie *>(26);
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    this->insert(word, 0);
  }
  void insert(string word, int iterator)
  {
    if (iterator == word.size())
    {
      this->hasWord = true;
      return;
    }
    int chara = word[iterator] - 'a';
    auto next = x[chara] ? x[chara] : new Trie();
    next->insert(word, iterator + 1);
    x[chara] = next;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    return search(word, 0);
  }
  bool search(string word, int iterator)
  {
    if (iterator == word.size())
      return hasWord;
    int chara = word[iterator] - 'a';
    auto next = x[chara];
    if (next)
      return next->search(word, iterator + 1);
    else
      return false;
  }

  bool searchConcatenated(string &st, int index, int count, unordered_map<int, bool> &cache)
  {

    auto p = this;
    if (cache.count(index) > 0){
      return cache[index];
    }

    for (int i = index; i < st.size(); ++i)
    {
      auto &ch = st[i];
      if (p->x[ch - 'a'])
      {
        p = p->x[ch - 'a'];
        if (p->hasWord && this->searchConcatenated(st, i + 1, count + 1, cache))
        {
          return true;
        }
      }
      else
      {
        cache[index] = false;
        return false;
      }
    }
    if(count <= 1)
      return false;
    return (index >= st.size()) || p->hasWord;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    return startsWith(prefix, 0);
  }
  bool startsWith(string prefix, int iterator)
  {
    if (iterator == prefix.size())
      return true;
    int chara = prefix[iterator] - 'a';
    auto next = x[chara];
    if (next)
      return next->startsWith(prefix, iterator + 1);
    else
      return false;
  }
};

class Solution
{
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
  {
    Trie *trie = new Trie();
    for (auto &word : words)
      trie->insert(word);

    vector<string> ret;
    for (auto &word : words)
    {
      unordered_map<int, bool> cache;
      if (trie->searchConcatenated(word, 0, 0, cache))
      {
        ret.push_back(word);
      }
    }
    return ret;
  }
};

int main()
{
  vector<string> input{"rfkqyuqfjkx", "", "vnrtysfrzrmzl", "gfve", "qfpd", "lqdqrrcrwdnxeuo", "q", "klaitgdphcspij", "hbsfyfv", "adzpbfudkklrw", "aozmixr", "ife", "feclhbvfuk", "yeqfqojwtw", "sileeztxwjl", "ngbqqmbxqcqp", "khhqr", "dwfcayssyoqc", "omwufbdfxu", "zhift", "kczvhsybloet", "crfhpxprbsshsjxd", "ilebxwbcto", "yaxzfbjbkrxi", "imqpzwmshlpj", "ta", "hbuxhwadlpto", "eziwkmg", "ovqzgdixrpddzp", "c", "wnqwqecyjyib", "jy", "mjfqwltvzk", "tpvo", "phckcyufdqml", "lim", "lfz", "tgygdt", "nhcvpf", "fbrpzlk", "shwywshtdgmb", "bkkxcvg", "monmwvytby", "nuqhmfj", "qtg", "cwkuzyamnerp", "fmwevhwlezo", "ye", "hbrcewjxvcezi", "tiq", "tfsrptug", "iznorvonzjfea", "gama", "apwlmbzit", "s", "hzkosvn", "nberblt", "kggdgpljfisylt", "mf", "h", "bljvkypcflsaqe", "cijcyrgmqirz", "iaxakholawoydvch", "e", "gttxwpuk", "jf", "xbrtspfttota", "sngqvoijxuv", "bztvaal", "zxbshnrvbykjql", "zz", "mlvyoshiktodnsjj", "qplci", "lzqrxl", "qxru", "ygjtyzleizme", "inx", "lwhhjwsl", "endjvxjyghrveu", "phknqtsdtwxcktmw", "wsdthzmlmbhjkm", "u", "pbqurqfxgqlojmws", "mowsjvpvhznbsi", "hdkbdxqg", "ge", "pzchrgef", "ukmcowoe", "nwhpiid", "xdnnl", "n", "yjyssbsoc", "cdzcuunkrf", "uvouaghhcyvmlk", "aajpfpyljt", "jpyntsefxi", "wjute", "y", "pbcnmhf", "qmmidmvkn", "xmywegmtuno", "vuzygv", "uxtrdsdfzfssmel", "odjgdgzfmrazvnd", "a", "rdkugsbdpawxi", "ivd", "bbqeonycaegxfj", "lrfkraoheucsvpi", "eqrswgkaaaohxx", "hqjtkqaqh", "berbpmglbjipnuj", "wogwczlkyrde", "aqufowbig", "snjniegvdvotu", "ocedkt", "bbufnxorixibbd", "rzuqsyr", "qghoy", "evcuanuujszitaoa", "wsx", "glafbwzdd", "znrvjqeyqi", "npitruijvyllsi", "objltu", "ryp", "nvybsfrxtlfmp", "id", "zoolzslgd", "owijatklvjzscizr", "upmsoxftumyxifyu", "xucubv", "fctkqlroq", "zjv", "wzi", "ppvs", "mflvioemycnphfjt", "nwedtubynsb", "repgcx", "gsfomhvpmy", "kdohe", "tyycsibbeaxn", "wjkfvabn", "llkmagl", "thkglauzgkeuly", "paeurdvexqlw", "akdt", "ihmfrj", "janxk", "rqdll", "cyhbsuxnlftmjc", "yybwsjmajbwtuhkk", "ovytgaufpjl", "iwbnzhybsx", "mumbh", "jqmdabmyu", "br", "lwstjkoxbczkj", "vhsgzvwiixxaob", "fso", "qnebmfl", "ooetjiz", "lq", "msxphqdgz", "mqhoggvrvjqrp", "xbhkkfg", "zxjegsyovdrmw", "jav", "mshoj", "ax", "biztkfomz", "hujdmcyxdqteqja", "gqgsomonv", "reqqzzpw", "lihdnvud", "lznfhbaokxvce", "fhxbldylqqewdnj", "rlbskqgfvn", "lfvobeyolyy", "v", "iwh", "fpbuiujlolnjl", "gvwxljbo", "ypaotdzjxxrsc", "mwrvel", "umzpnoiei", "ogwilaswn", "yw", "egdgye", "hsrznlzrf", "mwdgxaigmxpy", "yaqgault", "dtlg", "cyvfiykmkllf", "zxqyhvizqmamj", "lvvgoifltzywueyp", "abinmy", "ppzaecvmx", "qsmzc", "iddymnl", "uskihek", "evxtehxtbthq", "jvtfzddlgch", "czohpyewf", "ufzazyxtqxcu", "brxpfymuvfvs", "xrrcfuusicc", "aqhlswbzievij", "rv", "udvmara", "upityz", "fecd", "suxteeitxtg", "dfuydrtbfypbn", "cypqodxr", "wikfuxwjht", "jrliuaifpp", "vkmxys", "wvpfyfpkvgthq", "rmajxis", "jncxgviyu", "av", "nmhskodmidaj", "lkfrimprrhen", "uip", "hstyopbvuiqc", "p", "vwduwmjpblqo", "fnxwgqtvwztje", "xwnbcuggl", "iehimvoymyjasin", "spsqiu", "flhyfac", "mqrbq", "pstsxhplrrmbeddv", "hnegtuxx", "alsyxezjwtlwmxv", "jtxytykkcku", "bhhlovgcx", "xhhivxnutkx", "had", "aysulvk", "m", "anhsyxli", "jdkgfc", "potn", "lcibpxkidmwexp", "gwoxjicdkv", "tltienw", "ngiutnuqbzi", "o", "tzlyb", "vumnwehj", "os", "np", "lhv", "uzvgyeette", "ipfvr", "lpprjjalchhhcmh", "k", "pciulccqssaqgd", "tp", "dmzdzveslyjad", "wtsbhgkd", "eouxbldsxzm", "vhtonlampljgzyve", "xhnlcrldtfthul", "xhflc", "upgei", "rlaks", "yfqvnvtnqspyjbxr", "phouoyhvls", "voibuvbhhjcdflvl", "rgorfbjrofokggaf", "dqhqats", "zchpicyuawpovm", "yzwfor", "koat", "pybf", "fhdzsbiyjld", "gznfnqydisn", "xz", "po", "tcjup", "wygsnxk", "kqlima", "fgxnuohrnhg", "publurhztntgmimc", "zuufzphd", "iucrmmmjqtcey", "wnnbq", "rghzyz", "ukjqsjbmp", "mdtrgv", "vyeikgjdnml", "kxwldnmi", "apzuhsbssaxj", "tkbkoljyodlipof", "nkq", "ktwtj", "vgmkgjwle", "t", "agylw", "vomtuy", "jbtvitkqn", "vtdxwrclpspcn", "rdrls", "yxfeoh", "upj", "myctacn", "fdnor", "ahqghzhoqprgkym", "phiuvdv", "jp", "fdgpouzjwbq", "hqoyefmugjvewhxu", "qfzwuwe", "fnsbijkeepyxry", "oja", "qthkcij", "zpmqfbmnr", "ybaibmzonzqlnmd", "svo", "gjftyfehik", "jfrfgznuaytvaegm", "aljhrx", "odjq", "ogwaxrssjxgvnka", "zaqswwofedxj", "lugpktauixp", "dc", "odknlbvxrs", "jeobu", "vqythyvzxbcgrlbg", "hwc", "erpbaxq", "ujxcxck", "rrklkb", "wlrwyuy", "zmg", "yyhga", "xwdbycdu", "htedgvsrhchox", "wr", "suhesetv", "jonqwhkwezjvjgg", "sqqyrxtjkcalswq", "hvyimhe", "pjzdkmoue", "zbphmgoxq", "lbdlcumdgixjbcq", "ztzdjqmadthtdmv", "qcagsyqggcf", "if", "jpjxcjyi", "chyicqibxdgkqtg", "iwpdklhum", "wljmg", "micmun", "npdbamofynykqv", "ijsnfkpfy", "lmq", "oyjmeqvhcrvgm", "mqopusqktdthpvz", "fz", "r", "qbsqtipq", "nxtsnason", "xbpipyhh", "topsuqomfjrd", "islif", "gbndakaq", "bwnkxnwpzeoohlx", "hrtbfnq", "fguvomeepxoffg", "mat", "dzfpfnwbfuj", "onlvy", "cwcchvsasdylb", "rxfcztzqopdi", "ybrhodjn", "oqkijy", "ncvrjo", "dphbfaal", "xgtpdtkz", "sebevsopjvciwljf", "rcumyacqdapwczen", "mabkapuoud", "pbozezeygljfftvy", "bvazmzbndl", "vl", "qiaixdtbhqvlzd", "ffjfb", "svthrfmkoxbho", "cvet", "ucgqyvopafyttrh", "lbgihet", "naiqyufxffdw", "vruh", "uz", "ukffmudygjavem", "dccamymhp", "wofwgjkykm", "fbuujzxhln", "kmm", "lzandlltowjpwsal", "fapfvrmezbsjxs", "wiw", "sc", "soqlh", "hzaplclkwl", "gcdqbcdwbwa", "gadgt", "pgowefka", "juffuguqepwnfh", "nbuinl", "cpdxf", "sox", "fq", "lfnrhgsxkhx", "xrcorfygjxpi", "mwtqjwbhgh", "loc", "fkglorkkvx", "nlzdhucvayrz", "azefobxutitrf", "rlrstkcbtikklmh", "ggk", "sbphcejuylh", "nraoenhd", "zngyodiqlchxyycx", "rrbhfwohfv", "krzolrglgn", "cpjesdzy", "yoifoyg", "hqqevqjugi", "ahmv", "xgaujnyclcjq", "evhyfnlohavrj", "byyvhgh", "hyw", "kedhvwy", "ysljsqminajfipds", "rglnpxfqwu", "cibpynkxg", "su", "mbntqrlwyampdg", "nig", "ldhlhqdyjcfhu", "jfymrbafmyoc", "tyjmnhlfnrtz", "dlazixtlxyvm", "fbiguhsfuqo", "rhymsno", "rkbdlchs", "ocbbwwd", "astaiamnepwkya", "mplirup", "edkxjq", "g", "exlwulswtvot", "tlnc", "vnrrzerz", "ygeraoozbtt", "yyifkin", "eo", "ua", "qgztvqdolf", "rlzddjzcshvd", "khxkdxflwxme", "kk", "zylbhoaac", "cw", "iizic", "gcdxstpz", "kjwdqeg", "earjrncmmkdel", "kbesuhquepj", "nrzbllldgdmyrpgl", "hllwnqozf", "djpchowhwevbqvjj", "zsmhylnjpktb", "pxnktxkm", "fxwiaqqb", "qjwufmwresfsfaok", "aa", "d", "iobioqm", "svjgzk", "khbzp", "euexyudhrioi", "yqsj", "ngrwqpoh", "rwuvd", "eruffmlg", "bxzovyew", "faz", "pmvfvyguqdi", "jlxnoixsy", "hyfrdngjf", "ly", "eibcapetpmeaid", "tpnwwiif", "pfgsp", "kvhhwkzvtvlhhb", "pjxurgqbtldims", "rncplkeweoirje", "akyprzzphew", "wyvfpjyglzrmhfqp", "ubheeqt", "rmbxlcmn", "taqakgim", "apsbu", "khwnykughmwrlk", "vtdlzwpbhcsbvjno", "tffmjggrmyil", "schgwrrzt", "mvndmua", "nlwpw", "glvbtkegzjs", "piwllpgnlpcnezqs", "xkelind", "urtxsezrwz", "zechoc", "vfaimxrqnyiq", "ybugjsblhzfravzn", "btgcpqwovwp", "zgxgodlhmix", "sfzdknoxzassc", "wgzvqkxuqrsqxs", "dwneyqisozq", "fg", "vhfsf", "uspujvqhydw", "eadosqafyxbmzgr", "tyff", "blolplosqnfcwx", "uwkl", "puenodlvotb", "iizudxqjvfnky", "cjcywjkfvukvveq", "jrxd", "igwb", "dftdyelydzyummmt", "uvfmaicednym", "oai", "higfkfavgeemcgo", "naefganqo", "iqebfibigljbc", "ulicojzjfrc", "igxprunj", "cymbrl", "fqmwciqtynca", "zjyagi", "mzuejrttefhdwqc", "zyiurxvf", "wrjxffzbjexsh", "wrxw", "mhrbdxjwi", "htknfa", "wfrvxqdkhbwwef", "vqsghhhutdget", "cwupzrts", "hbjnb", "wpccoa", "nx", "howbzhaoscgyk", "bilt", "wqqatye", "zceuuwg", "jxzon", "kkfj", "bwsezd", "ifdegsyjtswselk", "xweimxlnzoh", "tqthlftjblnpht", "ww", "ss", "b", "jmruuqscwjp", "nxbk", "wd", "cqkrtbxgzg", "xhppcjnq", "cfq", "tkkolzcfi", "wblxki", "ijeglxsvc", "kcqjjwcwuhvzydm", "gubqavlqffhrzz", "hiwxrgftittd", "caybc", "ncsyjlzlxyyklc", "poxcgnexmaajzuha", "dhaccuualacyl", "mtkewbprs", "oncggqvr", "sqqoffmwkplsgbrp", "ioajuppvqluhbdet", "dzwwzaelmo", "afumtqugec", "wglucmugwqi", "zveswrjevfz", "nxlbkak", "pzcejvxzeoybb", "fd", "vewj", "ivws", "zjhudtpqsfc", "zcmukotirrxx", "zksmx", "umofzhhowyftz", "zbotrokaxaryxlk", "ueolqk", "dxmzhoq", "zvu", "cjl", "esfmqgvxwfy", "npbep", "vbgjtbv", "poeugoqynkbfiv", "fewjjscjrei", "yqssxzsydgllfzmo", "urxkwcypctjkabi", "wqtldwhjouas", "tovdtkr", "onzgeyddkqwuhnim", "ffxviyvsktqrfa", "qujhd", "pvcz", "hiyjlkxmeplnrvxg", "hdykehkefp", "vepcxhozpjxtreyn", "liguhuxudbnh", "f", "ordxzm", "klgohcmmbukz", "yrmooliaobbnlap", "dutnbetocxylcey", "ywdsjegd", "cr", "blbxhjsgcuoxmqft", "ngzdc", "srfyjjumcbxole", "dazwzwtdjoyuqeqj", "xazjarqgfm", "fxyfqbeoktcc", "qrsjchxp", "iltaqzawhgu", "sgenjcfxr", "yfikp", "dvwhbyumthkiktb", "walsx", "jyajrkcvysicisab", "brdeumb", "tviihjwxdcz", "dnrrgmem", "ydgxlrjzucxyid", "cdvdpvjlagwmg", "ngnpxjkxims", "gvyhnchlimsxc", "w", "jtizpezjl", "qe", "rjzv", "vhnqvi", "qm", "iedzqswrsnfmnn", "lt", "utqfcqyrrwm", "wtelvsqrru", "fjwrhjcrtbcytn", "qmqxceuohpiffaq", "rmoybqjjgdyo", "pmxttqftypfexlv", "tg", "qa", "iqbqjlnpbf", "kgaynkddbzllecd", "tccvslp", "curkxfoimnw", "fvnyqkzlheruxr", "iiygnzfov", "coqs", "oa", "eiu", "vzemmxtklis", "lxu", "nrwsjaxzwmh", "tdayz", "oxbbemejgosgcynf", "ykbcn", "hesvnctfvdsp", "ku", "rjhykpadahbhj", "at", "sxlngbtxmqr", "wqrom", "qzyabzrco", "rbbyklndcqdj", "cnsmgmwmpbgjq", "krvnaf", "qrwfajnfahyqocdb", "fnlaozmff", "vmoymbmytjvfcgt", "cijyy", "jdgwjbztl", "swmalgbgpaplqgz", "hfl", "typttkrpfvx", "tkzpzrscwbx", "bwfqqvjcukjbsg", "nxqmxr", "x", "eyavnz", "il", "dhthp", "eyelg", "npsoqsw", "reogbmveofvusdsx", "jvdrjkhxkq", "qzjbrpljwuzpl", "czqeevvbvcwh", "vzuszqvhlmapty", "yu", "yldwwgezlqur", "vorxwgdtgjilgydq", "pknt", "bgihl", "ckorgrm", "ixylxjmlfv", "bpoaboylced", "zea", "igfagitkrext", "ipvqq", "dmoerc", "oqxbypihdv", "dtjrrkxro", "rexuhucxpi", "bvmuyarjwqpcoywa", "qwdmfpwvamisns", "bhopoqdsref", "tmnm", "cre", "ktrniqwoofoeenbz", "vlrfcsftapyujmw", "updqikocrdyex", "bcxw", "eaum", "oklsqebuzeziisw", "fzgyhvnwjcns", "dybjywyaodsyw", "lmu", "eocfru", "ztlbggsuzctoc", "ilfzpszgrgj", "imqypqo", "fump", "sjvmsbrcfwretbie", "oxpmplpcg", "wmqigymr", "qevdyd", "gmuyytguexnyc", "hwialkbjgzc", "lmg", "gijjy", "lplrsxznfkoklxlv", "xrbasbznvxas", "twn", "bhqultkyfq", "saeq", "xbuw", "zd", "kng", "uoay", "kfykd", "armuwp", "gtghfxf", "gpucqwbihemixqmy", "jedyedimaa", "pbdrx", "toxmxzimgfao", "zlteob", "adoshnx", "ufgmypupei", "rqyex", "ljhqsaneicvaerqx", "ng", "sid", "zagpiuiia", "re", "oadojxmvgqgdodw", "jszyeruwnupqgmy", "jxigaskpj", "zpsbhgokwtfcisj", "vep", "ebwrcpafxzhb", "gjykhz", "mfomgxjphcscuxj", "iwbdvusywqlsc", "opvrnx", "mkgiwfvqfkotpdz", "inpobubzbvstk", "vubuucilxyh", "bci", "dibmye", "rlcnvnuuqfvhw", "oorbyyiigppuft", "swpksfdxicemjbf", "goabwrqdoudf", "yjutkeqakoarru", "wuznnlyd", "vfelxvtggkkk", "mxlwbkbklbwfsvr", "advraqovan", "smkln", "jxxvzdjlpyurxpj", "ssebtpznwoytjefo", "dynaiukctgrzjx", "irzosjuncvh", "hcnhhrajahitn", "vwtifcoqepqyzwya", "kddxywvgqxo", "syxngevs", "batvzmziq", "mjewiyo", "pzsupxoflq", "byzhtvvpj", "cqnlvlzr", "akvmxzbaei", "mwo", "vg", "ekfkuajjogbxhjii", "isdbplotyak", "jvkmxhtmyznha", "lqjnqzrwrmgt", "mbbhfli", "bpeohsufree", "ajrcsfogh", "lucidbnlysamvy", "tutjdfnvhahxy", "urbrmmadea", "hghv", "acnjx", "athltizloasimp", "gu", "rjfozvgmdakdhao", "iephs", "uztnpqhdl", "rfuyp", "crcszmgplszwfn", "zihegt", "xbspa", "cjbmsamjyqqrasz", "ghzlgnfoas", "ljxl", "cnumquohlcgt", "jm", "mfccj", "hfedli", "vtpieworwhyiucs", "tdtuquartspkotm", "pnkeluekvelj", "ugrloq", "zljmwt", "fkyvqguqq", "tpjidglpxqfxv", "l", "tvvimvroz", "yy", "opwyfovdz", "pwlumocnyuoume", "vjqpzkcfc", "ihicd", "dtttiixlhpikbv", "goblttgvmndkqgg", "gwsibcqahmyyeagk", "prtvoju", "lcblwidhjpu", "kbu", "pey", "gkzrpc", "bqajopjjlfthe", "bc", "lqs", "zkndgojnjnxqsoqi", "zyesldujjlp", "drswybwlfyzph", "xzluwbtmoxokk", "bedrqfui", "opajzeahv", "lehdfnr", "mnlpimduzgmwszc", "velbhj", "miwdn", "wruqc", "kscfodjxg", "wcbm"};
  auto result = Solution().findAllConcatenatedWordsInADict(input);
  for (auto &ret : result)
    cout << ret << endl;
  return 0;
}