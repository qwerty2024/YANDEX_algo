﻿#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input);

    vector<vector<int>> ab;
    ab.resize(N);
    for (int i = 0; i < N; i++)
        ab[i].resize(2, 0);


    for (int i = 0; i < N; i++)
    {
        getline(cin, input, ' ');
        ab[i][0] = stoi(input);
        getline(cin, input);
        ab[i][1] = stoi(input);
    }



    vector<int> add;
    vector<int> miss;

    for (int i = 0; i < N; i++)
    {
        if (ab[i][0] - ab[i][1] < 0)
            miss.push_back(i);
        else
            add.push_back(i);
    }

    if (miss.size() == 0) // если нет с отрицательной доходностью
    {
        int iimax = 0;
        unsigned long long max = ab[0][1];
        for (int i = 1; i < N; i++)
        {
            if (ab[i][1] > max)
            {
                iimax = i;
                max = ab[i][1];
            }
        }

        max = 0;
        for (int i = 0; i < N; i++)
        {
            if (i != iimax) max += ab[i][0] - ab[i][1];
        }

        cout << max + ab[iimax][0] << endl;

        for (int i = 0; i < N; i++)
        {
            if (i != iimax) cout << i + 1 << " ";
        }

        cout << iimax + 1 << endl;
        return 0;
    }

    if (add.size() == 0) //если нет с положительной доходностью
    {
        int iimax = 0;
        int max = ab[0][0];
        for (int i = 1; i < N; i++)
        {
            if (ab[i][0] > max)
            {
                iimax = i;
                max = ab[i][0];
            }
        }

        cout << max << endl;
        cout << iimax + 1 << " ";

        for (int i = 0; i < N; i++)
        {
            if (i != iimax) cout << i + 1 << " ";
        }
        cout << endl;
        
        return 0;
    }


    int imax = miss[0];
    int max = ab[imax][0];
    for (int i = 1; i < miss.size(); i++)
    {
        if (max < ab[miss[i]][0])
        {
            imax = miss[i];
            max = ab[miss[i]][0];
        }
    }

    int imin = add[0];
    int min = ab[imin][0];
    for (int i = 1; i < add.size(); i++)
    {
        if (min > ab[add[i]][1])
        {
            imin = add[i];
            min = ab[add[i]][1];
        }
    }
/*
ответы расходятся тут
12 1
879 1

мой
1   91410744 246645879
879 229201036 786799

бот
1  91410744 246645879
12 989222712 955828702
*/
    unsigned long long res = 0;

    // найти максимум Б у положительных 
    int maxB = ab[add[0]][1];
    int iiiimax = add[0];
    for (int i = 0; i < add.size(); i++)
    {
        if (maxB < ab[add[i]][1])
        {
            iiiimax = add[i];
            maxB = ab[add[i]][1];
        }
    }

    if (ab[iiiimax][0] > ab[iiiimax][0] - ab[iiiimax][1] + ab[imax][0])
    {
        // не складываем
        for (int i = 0; i < add.size(); i++)
        {
            if (iiiimax != add[i]) res += ab[add[i]][0] - ab[add[i]][1];
        }
        res += ab[iiiimax][0];
        cout << res << endl;

        for (int i = 0; i < add.size(); i++)
        {
            if (iiiimax != add[i]) cout << add[i] + 1 << " ";
        }
        cout << iiiimax + 1 << " ";

        for (int i = 0; i < miss.size(); i++)
        {
            cout << miss[i] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        if (ab[imax][0] > ab[imin][1])
        {
            // стоит складывать
            for (int i = 0; i < add.size(); i++)
            {
                res += ab[add[i]][0] - ab[add[i]][1];
            }
            res += ab[imax][0];
            cout << res << endl;

            for (int i = 0; i < add.size(); i++)
            {
                if (add[i] != imin) cout << add[i] + 1 << " ";
            }
            cout << imin + 1 << " " << imax + 1 << " ";

            for (int i = 0; i < miss.size(); i++)
            {
                if (miss[i] != imax) cout << miss[i] + 1 << " ";
            }
            cout << endl;
        }
        else
        {
            // не стоит складывать
            for (int i = 0; i < add.size() - 1; i++)
            {
                res += ab[add[i]][0] - ab[add[i]][1];
            }
            res += ab[add[add.size() - 1]][0];
            cout << res << endl;

            for (int i = 0; i < add.size(); i++)
            {
                cout << add[i] + 1 << " ";
            }

            for (int i = 0; i < miss.size(); i++)
            {
                cout << miss[i] + 1 << " ";
            }
            cout << endl;
        }
        
    }


/*
5
1000 999
10 5
10 3
10 1
1 5
23
1 2 3 4 5
 
5
10 16
100 130
200 250
5 13
2 11
200


5
10 6
100 30
200 50
5 3
2 1
277

2
17 27
1 100

6
822889311 446755913
715477619 181424399
61020590 573085537
480845266 448565595
135599877 389312924
160714711 449656269
1391031884
1 2 4 3 5 6

7
160714711 449656269
822889311 446755913
135599877 389312924
480845266 448565595
561330066 605997004
61020590 573085537
715477619 181424399
1503796355
7 2 4 5 1 3 6


3
1 5
8 2
4 4

2
7 6
7 4




100
111320504 366248673
795507844 954204512
546838875 712009693
290835305 721735267
159760440 816249993
93130607 966307226
595605750 185676190
101163040 327953325
149989495 796807778
873966806 934677835
353505649 542006342
34675204 610858472
944380729 950778206
309415438 788425492
182148581 654353213
488822087 806137988
134394102 247631614
167458327 874682073
883735100 632723121
523938839 979522399
925719726 983206610
350239483 467400369
990607689 211428413
679513171 560686330
28496614 617351072
557631733 568204776
637078930 675645627
226876035 273616448
315777484 500150364
109378997 128408775
257257617 842813570
372938362 689340674
763878605 823076990
81019893 415891345
177707077 851174031
449656269 160714711
798834446 880013416
715477619 181424399
403642447 409974917
129586135 648382742
429014248 477195779
318390928 789081312
522202490 154945342
70663703 607539685
50092962 764820747
399623565 444888018
195282969 722460568
848680263 249403991
439261835 488135242
44558618 509676517
708426597 801141060
592048652 794863955
534003430 754153930
624878749 950548839
650693494 63219754
283079237 285093436
1886864 647773264
975361464 763371317
389312924 135599877
802436733 916523881
5886223 751491209
167794516 598207395
386576826 388597517
201424080 853308909
86335353 893588013
308811749 381966915
294431279 359623093
48946904 641467344
13088544 753246258
205576634 414210634
573085537 61020590
822889311 446755913
100619633 644464578
526473179 802153704
79042330 652683534
216598847 687316171
751365018 759985962
104163021 591339377
46265148 118376683
178280863 287113365
24539167 132508024
492197753 953546232
955828702 989222712
605997004 561330066
479498871 668773827
23215822 116925841
194676444 408180613
619315470 692717061
867977435 395940406
469786584 849551810
161055688 504667277
62190969 830257761
402127003 503811256
480845266 448565595
249519268 512360334
56157847 704502692
786799 229201036
383140962 520723210
655702582 632532642
566237741 569231264
6817833413
7 19 23 24 36 38 43 48 55 58 59 72 84 89 94 99 71 83 1 2 3 4 5 6 8 9 10 11 12 13 14 15 16 17 18 20 21 22 25 26 27 28 29 30 31 32 33 34 35 37 39 40 41 42 44 45 46 47 49 50 51 52 53 54 56 57 60 61 62 63 64 65 66 67 68 69 70 73 74 75 76 77 78 79 80 81 82 85 86 87 88 90 91 92 93 95 96 97 98 100

1000
91410744 246645879
548005576 229486358
803980871 224901874
861095072 316710734
361173233 431221412
795325398 708524470
865945442 510337292
391169760 344881060
474897219 313809702
818736355 143887114
867977435 395940406
989222712 955828702
898378286 630958529
448454752 323222515
297984506 102934274
241509680 729781601
799060848 747512043
821796166 704644716
723296526 405421751
672438788 284229429
707052188 580762090
310653206 92689764
647773264 1886864
984771647 870250472
477195779 429014248
374970926 22699716
654353213 182148581
290018915 266342772
683846744 641731565
853308909 201424080
975361464 763371317
839369148 54455460
41702076 35630286
66586386 697474708
887289915 375003591
839612452 188350842
822503889 63528727
676758770 701890342
822960358 195008351
475702181 52722797
795299450 221918478
644464578 100619633
856809151 113322277
572086080 75990328
845328373 641163481
855532712 830303389
163491258 642337414
272790805 12487543
933414151 869737693
936502927 157053937
990806263 69072845
392618405 17822742
978760161 258865505
925181073 905657623
259874497 234459686
614620344 546082731
607539685 70663703
505480583 140463626
979846008 1553557
692717061 619315470
882837248 450853349
860502037 76254750
381978823 642160153
932276053 10818579
966307226 93130607
522202490 154945342
790957950 448217492
868258293 601504792
668406063 214777757
805550377 173370603
842225782 610205009
838695651 510807663
903645019 19307202
630767721 397753309
714102217 76032347
773280318 81596104
31124020 27662047
785491496 309484861
596595836 660454565
44831716 230735370
926584611 113439014
890345633 698826176
394520647 212413822
932458724 688838759
883735100 632723121
971728252 683382145
549039802 373692344
935843149 864825593
810121926 901454728
870614257 134376766
900786318 828666453
224157296 195668420
571756349 389739404
885728047 522320816
634905833 351540859
347286668 992000230
652683534 79042330
754780130 249732849
456945165 689886351
573085537 61020590
898737407 87057548
931648337 883432399
209061239 912792948
949067054 10942580
792829832 462453470
187720542 89048078
675645627 637078930
753907323 644986163
991809986 916856495
307706267 78710890
989194729 481096661
955953329 186165967
704555331 190671721
736616009 335219389
945406352 604903227
773972581 759431052
409974917 403642447
623700102 427283045
788425492 309415438
445694255 13392014
483895144 109651311
774367503 246426771
484938204 73832124
745256215 162120278
983206610 925719726
644356924 346894462
290466313 144945880
271169048 274131530
509826417 481129474
279212387 568607831
716863001 210113201
912239375 192452488
722460568 195282969
227149886 220642171
516757868 143773730
697640875 658067668
229404053 182016505
494206699 521784267
796807778 149989495
303010676 704946868
506668881 606502126
380791293 691681970
770241310 99442555
520980926 144025593
921823721 187477750
830121995 347142775
896008586 733230064
583088397 12834774
892179082 677927799
173976640 263184499
912825298 84207599
287081186 278758050
591705892 379542464
131244295 77462480
863063846 860591597
964944213 174731736
116925841 23215822
748710846 668816604
108051037 33083917
698067996 522854875
930259756 263851811
241415953 270498760
327953325 101163040
998777002 596198887
562611972 270707205
780956012 692861714
721735267 290835305
986033787 297532716
957935764 869881268
580873359 89678196
543889001 283422981
324898724 726273908
227162762 890149318
366248673 111320504
880013416 798834446
846351364 32299388
650693494 63219754
292784326 590644522
820696220 258680502
579166863 140425005
370434723 108254169
157983529 79700637
531081237 315914026
504187215 293100719
114890626 270438055
659482837 537563075
764939541 719796225
163115632 15494960
341220019 273455581
547483434 928632942
823500041 408560785
696951453 31064396
424838447 725026440
432727243 279902683
787852602 37108011
988421724 529058271
806899006 123622730
667802501 292470508
653367096 46911175
395268645 271812554
614799779 722649818
679536279 365046828
492782430 140553949
956112038 171453958
233361897 86538575
470999790 611271562
743631635 416159222
953546232 492197753
145730672 829778395
591099920 374606691
465963980 20639342
475840131 93898342
689340674 372938362
341359628 782440263
670920190 583959407
994923008 847405138
937143211 650184426
880583937 119679023
990381081 299990774
761655077 742714169
982751500 323373465
698803937 266029976
476944990 237440807
204592126 833919119
911807849 586444518
750624966 110371857
698520775 113406791
296756002 618332642
288804195 33938096
886760232 164270230
176944354 173337362
740909672 652624653
569035560 493012020
365129176 328422061
424832217 408482740
883406197 375791896
125851022 86647658
333397200 296553302
540438974 925988647
946881177 936471280
964270450 838612495
547637388 323210461
736255485 135611857
271977507 572310841
791147147 771614883
608569156 195392501
899172733 619229311
979522399 523938839
331602871 21147886
808127747 1114144
652834766 248109316
781032900 771878795
796563373 747400415
340825048 101830052
69237403 900889144
879737597 276077119
147830417 340381194
864841590 580688925
391522818 265812386
743101581 869721332
206816355 780548480
958414883 877569466
660203013 2341737
246520088 786325930
962707075 664549714
537256772 614134346
802268435 762146675
467309215 741284689
515228227 264273803
797638095 237171256
893236340 68274237
740959314 572869801
287113365 178280863
780886038 132531931
245866596 858223867
905066814 787808720
388597517 386576826
166000841 966162621
765785507 254669356
888349177 868620964
317952703 186778100
573415781 181668397
66039606 462693153
339777702 59790422
132508024 24539167
282101980 39283741
994220419 883267880
849643485 829505271
184888154 250418315
482926679 250091780
509032071 174161540
177942692 188329960
622156745 203298686
847802556 175745740
649658174 565478426
849551810 469786584
371413980 81125931
712009693 546838875
606359195 972649617
755066481 46630379
804256883 220396101
511748574 271078123
570509338 486774113
857964611 221969252
801204888 808418512
48817723 43979214
687316171 216598847
858767563 98765864
136395870 588630328
356090865 90386075
614726104 172856996
327359101 129251286
976594538 82425981
828164773 419323075
810909378 735454332
922517338 667923477
950778206 944380729
156995953 46821273
166369987 13931474
479325303 459742076
679617176 417192701
128408775 109378997
794515904 11830993
466624209 215220456
300548946 867399646
514613173 580097514
33599692 7792739
410747700 935043271
583902633 9247475
135268542 791403843
504667277 161055688
92899668 83593393
394850750 321420047
307874110 236108090
869974579 297280879
858794880 666048736
938581100 342313970
652331593 586937111
655678072 171121142
715233367 625123687
677559299 627762380
933667853 839662329
789360291 637943483
359284240 339854567
93979792 310323727
835533295 690381188
752361849 894350125
581639910 189996214
944917648 576196169
991164833 864495133
552783731 23011981
614056069 600377760
612280186 491408847
954909986 281289289
224461867 103169918
641467344 48946904
926560922 600021616
65033544 39987068
575053584 341235334
941517812 425714460
460107987 909822663
528540632 254748072
197108397 311181111
555962410 696352187
512360334 249519268
746436060 161731917
869549736 402863359
789081312 318390928
435206294 235150371
647786150 574016318
874376810 308228539
252822188 495310058
665199349 220514067
759985962 751365018
939952030 376980345
492428203 460251876
923757008 743056901
548217560 123070005
869938441 669206298
169994147 736743618
956617424 125093527
31270019 13474566
679513171 560686330
252313115 41562694
611465376 317688651
817601192 507005048
887077374 331495347
434107501 170565074
415678943 409022212
991309251 649541044
312590466 295065702
874050805 705288857
684959823 263152004
255738909 20226053
89174319 824119443
772635877 170755858
55343317 28086779
267768873 562311400
638051902 320562164
788421425 369006135
292262353 563283682
749552089 977744858
712004532 485935480
844962515 362284849
636867087 403263838
725408233 283104235
610858472 34675204
616010479 466275704
679352833 756112856
317666007 790953040
293990056 281577049
390120279 218530855
137861306 241641608
492813098 154968908
993308956 89545461
664017192 94318769
385486788 326640935
30822278 200016848
698405446 391683689
779320210 485120445
458846224 450353057
846037796 750300860
929518039 266844587
613913204 15683167
823248749 570210864
453041955 199124670
767157259 129434214
95359 427294662
703448200 976232815
546095536 724108280
749950445 88973587
29164499 723251207
476486645 360885687
344581913 221701796
652244334 435380306
223028635 105979921
781130281 957653166
697767085 147907673
806137988 488822087
492877456 37197306
775917341 25750849
220030846 616055561
786313657 419538653
972688741 598562834
728606450 138146615
954204512 795507844
755248736 201078863
906987688 732161086
832722683 817690798
324559352 385505333
243411680 54754319
692205376 604614496
451120787 61120314
838978166 780208670
990546015 383286840
66257496 648708941
591339377 104163021
595605750 185676190
52852438 306129011
786997108 64309775
641586139 510039889
780901477 82044083
949536858 573416055
700480288 620622083
821162081 4436853
770786828 337550614
637132250 545001846
99708768 44904715
287252610 62345302
488603434 246707310
142706811 122874667
804429679 84257473
743739013 592243157
428525427 64013839
303936871 292911562
318021484 70064859
809536481 281216787
755312233 732473709
273616448 226876035
796412294 353994938
463069371 17653797
703574544 405892507
486883878 454808665
830297328 129288841
291287609 942378317
488607150 364726135
992986771 304829034
655702582 632532642
980481855 240200897
384414836 804838253
913487604 373490043
996308212 405790019
927105156 201314351
730364835 358261453
597529102 410791995
507594387 483556174
806967259 10808051
167061262 144545453
348287978 334608051
439950120 199188284
822094394 67998455
451412652 142324125
166931517 879395648
776482116 581772448
975752491 327644854
761538884 616128898
599085880 375561266
518801594 841721142
963474706 330522327
624490708 498921490
174764001 251932827
504015192 480577360
699117615 258602467
893529661 557119343
605997004 561330066
942900186 710928195
247631614 134394102
705972908 380349150
764820747 50092962
515939466 66675232
439568235 325415581
971407214 660840178
786568198 460039418
376637178 970649270
375636071 284459096
954175747 416160165
868083202 568793230
571093085 219904511
901904933 507788867
348906161 177341361
118376683 46265148
464155679 9186944
449656269 160714711
436812929 977112108
906062792 492472138
730146278 97660809
409299718 47417634
757656688 982344302
720798915 652158831
256735240 899805240
786468448 504406004
949619667 482918542
160564043 241483211
592346658 395039075
163061644 766647665
916523881 802436733
201123156 564442667
517647233 688706795
850933992 319528247
520723210 383140962
745449226 965961495
465983043 78120940
582609584 462567606
869535768 142753973
861452622 578457103
338910880 795259425
195687360 23950828
268095476 88458850
992378011 442169964
591318531 282097312
564120019 292539849
247313093 512380601
766247356 659246582
932973615 547584600
367145125 227162878
655597694 329099152
668054446 450228308
954874671 142124659
237993832 33766057
979067727 204479846
636481400 623753661
173019921 815949938
855115512 343610012
704502692 56157847
747855785 353832292
284903834 194823757
394765357 198652737
579831511 318917561
976452260 242864826
409662600 58724863
56373410 814027329
802153704 526473179
890513053 822282089
753976456 64865714
437175845 75697868
262925513 88744616
568204776 557631733
423308130 328001819
626532983 406502463
114540160 81219817
905419812 286310233
961784550 874366552
403943695 94083210
488389379 344793441
207333883 74436657
790898125 369658821
308690380 213596461
429969450 31196250
365811031 85974877
956563612 120718967
118341163 87493676
916179629 636046722
301848283 191322670
637358875 8210929
630114825 532164253
842371166 270750491
415891345 81019893
529221191 102946672
775657713 447953931
990607689 211428413
285093436 283079237
539921137 710010816
676169452 431487752
644781871 318860379
593117640 758234472
806121958 841591510
786273050 634928069
933987336 800668173
660598166 490068958
715477619 181424399
674027804 539731581
392366961 213083915
751491209 5886223
777634286 556255213
619843643 909344853
509676517 44558618
271099678 197636530
416919527 174499885
814911687 667065905
599514852 846166940
71913844 655657097
869851924 32588141
273509011 264995812
672075052 779180806
866368175 135641963
844549700 250328268
319047470 620707513
806354421 93506117
859506309 281135715
119068298 236937443
563982537 878452667
259517889 45823890
864705758 546187414
768466839 544206738
673354207 506411642
246738322 44908017
221095173 274063493
536934571 87462608
807485096 664313500
318519110 54296706
34332542 499179637
614160183 366920274
151307722 79777808
867195563 505817949
404214048 183502698
727751791 130932510
341583870 31413166
920559861 372723449
959361844 253670361
891858291 222504087
794085266 501686387
807399712 237104904
703530436 642379648
542006342 353505649
359623093 294431279
735838541 888583781
467554780 419599685
414210634 205576634
268671143 48109037
414624887 272323321
605116303 378501544
712020979 990510779
916748690 458753065
830257761 62190969
204023177 229996119
618903267 576997455
932893631 573299368
876032964 857333380
415668216 126206023
868771642 642348245
992951822 668618263
859505386 181899902
859769947 964638202
450102954 94456833
717099376 941445096
709111005 397105760
467400369 350239483
819604817 631557780
884129056 867314637
157327928 462858183
759176102 493712880
888319856 117060579
744009990 665673433
235000644 311422099
432665973 280634880
716438543 456602917
344251847 857727755
903570083 768521781
816249993 159760440
978456870 335179974
752761841 49855192
265155793 188388580
950548839 624878749
117523708 105059466
823076990 763878605
816589445 674989749
771263555 124228398
481542116 230351761
595039482 225532811
648382742 129586135
491548416 445398954
219431294 135785263
418604238 982814459
703645398 117764967
998415717 256640958
259500443 350576781
839320819 813385034
468398889 360211363
795603753 346784386
870118456 813988315
979775022 2838207
764569694 729236512
928795952 390274782
285139426 110161743
794863955 592048652
734217966 46659198
733629117 369536152
607205006 263696835
292996992 929101820
575966848 83323568
917717315 596096057
859035757 219184735
410940982 211125034
814964056 776705110
658703641 549362796
714688269 189666275
798883231 472454094
900229081 550518854
637789988 359960310
253410043 150981561
269163619 174764823
707952930 41476794
422796890 20002885
859141055 730223209
907399191 723777409
917805751 768969642
308049145 795612011
429713899 157028848
988176662 250879009
783544947 252718236
771970764 788076655
778991105 273656700
828297878 708332962
817298992 981230172
305450538 735029379
963867061 480480224
6686791 918967727
455981010 398364038
853334711 244592748
946476063 408974210
217363248 193734747
30048394 14483369
908123162 265752948
187627660 9446363
385548068 373530081
643936296 269178877
428550068 231077759
634668792 603183481
234282537 658957283
909529507 903193471
800331658 741914258
233156310 183354323
908752241 394663663
774589246 267388887
378355989 335778097
670062994 466910579
881717794 638572318
370987465 797087461
825785904 54519829
497798713 916143321
758708126 215994927
383622075 285589314
760661678 35012096
664661974 452252617
85111736 77397006
592774683 236850781
873198969 609397900
704195198 46457208
893767324 185814907
827189866 400889951
387341124 265542485
977959971 800468475
754153930 534003430
390613997 817151226
753246258 13088544
82039519 265782155
417976248 337559654
239163812 5105
381966915 308811749
853891887 462836342
338408256 221701563
426085341 452497185
846287685 827277376
881310329 54235631
919834406 512577288
421440040 300258570
994634407 19439554
729176861 381936987
493685211 399188091
135105385 7448991
556323720 569888023
992924495 443223298
814056498 124379743
573001018 145902930
360807626 333168838
960710482 514603948
286470276 251313879
350356034 130993339
444888018 399623565
978994295 941276842
617351072 28496614
196433080 67939183
892471111 589556711
183852221 220474366
34063162 597963406
558706650 177281530
589012361 2036598
299213445 237789781
334433620 127597675
858876459 360149352
752073982 647660811
981202451 74675372
446784415 145594753
665704250 246338085
89108654 835445597
636767944 222640175
569231264 566237741
636877563 342816428
430796457 359924606
503811256 402127003
33129763 240276311
933042445 684414415
453735982 837874952
851174031 177707077
923320636 54305884
964127525 129951756
847854470 22834012
435854239 155257804
932027036 363841107
921229950 337751904
432281513 69651909
656270823 98575458
408180613 194676444
500150364 315777484
864675718 997814328
480845266 448565595
524422711 360646830
904412526 604499675
928478271 544659493
717141557 491733242
736470922 692682446
31090590 361591924
195665930 105866569
516933208 78359635
668773827 479498871
647938679 672548561
976506930 816945152
306630353 17927225
520679017 504833615
926978728 244891994
113571878 843930787
414970709 178383237
528246202 140945045
824386721 412925516
658129581 720361585
748392311 48263119
512492025 155047066
229201036 786799
942732325 955249484
804080775 768645120
461872168 289837536
389312924 135599877
782957648 44232127
739079324 71346501
893588013 86335353
672577741 115081854
474599018 423437993
901117103 799966160
832158671 65380664
87046404 287467680
321586476 344332491
822889311 446755913
831822173 541606471
913240294 572921936
704881272 149329252
896303191 315663991
446804567 280890658
521519286 203031824
647413210 604629715
681222532 207539682
547214346 101944929
848680263 249403991
91593295 83923093
607816874 174149530
538206076 145144922
676150792 583697087
185734283 946140090
881501697 236920328
480751294 128151462
773212014 277387183
943696775 872795801
522315040 136565356
771989534 941612965
953245506 99605515
777250793 379979628
662254290 178670355
814317150 305714608
615581287 489714458
590310385 192593521
412765555 634292382
557561418 604168211
875136596 630529864
481997517 114924971
477198686 339278866
955229481 159167136
489813910 156698095
86318129 43325267
178565087 658048000
437405889 613075370
932073395 322337018
535496501 445771464
993995664 161781829
845139189 301171378
247537641 57295785
642281141 496328569
551155288 362538741
842813570 257257617
744504025 559641085
763428561 631582405
293139584 396634902
542830725 523090638
671030508 299931317
336126462 51928247
621394596 236625820
938995043 264308101
49676737 612390031
441618301 201199211
912281794 678123967
333781996 102211795
584755218 239716852
240217865 291757645
919509487 724317246
915336988 293079002
176421461 145503300
276307582 353134540
801141060 708426597
134256996 79990764
736391473 399932810
934677835 873966806
990038735 806894778
755050998 333929577
672654771 125964635
878711472 535456097
519629328 733516149
760489960 178586756
524339699 677480119
530850883 48648412
309834135 109329776
874682073 167458327
662892041 867122688
488135242 439261835
535921586 445571579
800681391 775542398
747316851 26644478
875443459 308987252
953030320 909225937
725999075 280568700
41025855 20231165
777902307 92167371
851778114 519612598
868920338 84931254
598207395 167794516
406641905 422673761
261312511 881538438
604715833 358312263
221345964 528913466
949542703 902349721
287379982 579906215
142065043 30617279
545969730 279804648
680523049 592612227
221021171 142885675
694419567 254192274
907482059 526236415
786021323 359787425
405265837 354403483
639452096 548193546
542116379 187838073
530354723 79637436
942271408 63195395
277086265512
2 3 4 6 7 8 9 10 11 13 14 15 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 35 36 37 39 40 41 42 43 44 45 46 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 81 82 83 84 85 86 87 88 90 91 92 93 94 95 97 98 100 101 102 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 129 131 132 133 134 135 136 137 139 143 144 145 146 147 148 149 151 152 153 154 155 156 157 158 159 160 161 163 164 165 166 167 168 169 170 171 174 175 176 177 179 180 181 182 183 184 186 187 188 189 191 192 194 195 196 197 198 199 200 202 203 204 205 207 208 210 211 212 213 215 216 217 218 219 220 221 222 223 225 226 227 229 230 231 232 233 234 235 236 237 238 240 241 242 243 245 246 247 248 249 250 251 252 253 254 256 258 259 262 263 265 267 269 270 271 272 273 274 276 277 279 280 281 282 284 285 286 287 288 290 291 293 294 295 296 297 298 300 301 302 303 304 306 307 308 310 311 312 313 314 315 316 317 318 319 320 321 322 323 324 327 329 331 332 333 334 335 336 337 338 339 340 341 342 343 344 346 348 349 350 351 352 353 354 355 356 357 358 359 360 362 365 366 367 368 369 370 371 373 374 375 376 377 378 379 381 382 383 384 385 386 387 388 389 390 391 392 393 394 396 397 399 400 403 404 405 406 407 408 411 412 414 415 416 417 419 420 421 422 423 424 425 426 427 431 433 434 435 436 438 439 440 441 443 444 445 446 447 448 449 451 452 453 454 455 457 458 460 461 462 463 464 465 466 467 468 469 470 471 472 473 474 475 476 477 478 479 480 481 482 483 484 486 487 488 489 491 492 493 494 495 496 497 498 499 500 501 502 504 505 506 507 509 510 512 513 514 515 516 517 518 519 520 521 522 523 525 526 527 528 529 530 531 532 533 535 536 537 539 541 542 544 546 549 550 552 553 554 555 557 558 559 560 561 563 564 565 566 567 568 569 570 571 573 574 575 576 577 578 579 580 582 583 584 585 586 587 588 589 590 591 592 593 594 595 596 597 598 599 600 601 602 603 604 605 606 607 608 609 610 611 613 614 617 618 619 620 621 622 623 624 626 627 628 629 632 633 635 636 638 639 642 643 644 645 646 648 649 650 652 653 654 655 656 657 658 659 660 661 662 663 664 665 667 668 669 670 671 673 674 676 677 678 679 680 681 682 684 686 687 688 689 691 692 693 695 696 698 699 700 701 702 703 704 705 706 707 708 709 710 711 712 714 715 717 718 719 720 721 722 723 724 725 726 727 728 730 731 732 733 734 735 736 737 738 739 740 741 742 743 744 745 746 748 749 750 752 753 756 758 759 760 761 762 763 764 765 766 767 768 770 771 772 773 774 775 776 777 779 781 782 783 784 785 786 787 788 789 790 791 792 793 795 797 798 799 800 801 803 804 805 806 807 808 809 810 812 813 814 815 816 817 818 819 820 821 822 823 826 827 828 829 830 831 832 833 834 836 837 838 839 840 842 844 845 846 847 848 849 850 851 852 853 854 856 857 858 859 860 861 863 864 865 867 868 869 870 872 873 874 876 877 878 880 881 882 883 884 885 886 887 888 889 892 893 894 895 896 897 898 899 900 901 902 903 904 905 906 908 909 910 911 912 914 915 916 917 918 919 922 923 924 925 926 927 930 931 932 933 934 935 936 937 938 939 941 942 943 944 945 947 948 949 950 952 953 954 956 957 958 959 960 961 962 963 965 967 968 969 971 972 973 974 975 976 977 978 979 980 981 982 985 987 989 990 991 992 993 994 995 996 997 998 999 1000 12 1 5 16 34 38 47 63 79 80 89 96 99 103 128 130 138 140 141 142 150 162 172 173 178 185 190 193 201 206 209 214 224 228 239 244 255 257 260 261 264 266 268 275 278 283 289 292 299 305 309 325 326 328 330 345 347 361 363 364 372 380 395 398 401 402 409 410 413 418 428 429 430 432 437 442 450 456 459 485 490 503 508 511 524 534 538 540 543 545 547 548 551 556 562 572 581 612 615 616 625 630 631 634 637 640 641 647 651 666 672 675 683 685 690 694 697 713 716 729 747 751 754 755 757 769 778 780 794 796 802 811 824 825 835 841 843 855 862 866 871 875 879 890 891 907 913 920 921 928 929 940 946 951 955 964 966 970 983 984 986 988

277073169135
2 3 4 6 7 8 9 10 11 12 13 14 15 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 35 36 37 39 40 41 42 43 44 45 46 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 81 82 83 84 85 86 87 88 90 91 92 93 94 95 97 98 100 101 102 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 129 131 132 133 134 135 136 137 139 143 144 145 146 147 148 149 151 152 153 154 155 156 157 158 159 160 161 163 164 165 166 167 168 169 170 171 174 175 176 177 179 180 181 182 183 184 186 187 188 189 191 192 194 195 196 197 198 199 200 202 203 204 205 207 208 210 211 212 213 215 216 217 218 219 220 221 222 223 225 226 227 229 230 231 232 233 234 235 236 237 238 240 241 242 243 245 246 247 248 249 250 251 252 253 254 256 258 259 262 263 265 267 269 270 271 272 273 274 276 277 279 280 281 282 284 285 286 287 288 290 291 293 294 295 296 297 298 300 301 302 303 304 306 307 308 310 311 312 313 314 315 316 317 318 319 320 321 322 323 324 327 329 331 332 333 334 335 336 337 338 339 340 341 342 343 344 346 348 349 350 351 352 353 354 355 356 357 358 359 360 362 365 366 367 368 369 370 371 373 374 375 376 377 378 379 381 382 383 384 385 386 387 388 389 390 391 392 393 394 396 397 399 400 403 404 405 406 407 408 411 412 414 415 416 417 419 420 421 422 423 424 425 426 427 431 433 434 435 436 438 439 440 441 443 444 445 446 447 448 449 451 452 453 454 455 457 458 460 461 462 463 464 465 466 467 468 469 470 471 472 473 474 475 476 477 478 479 480 481 482 483 484 486 487 488 489 491 492 493 494 495 496 497 498 499 500 501 502 504 505 506 507 509 510 512 513 514 515 516 517 518 519 520 521 522 523 525 526 527 528 529 530 531 532 533 535 536 537 539 541 542 544 546 549 550 552 553 554 555 557 558 559 560 561 563 564 565 566 567 568 569 570 571 573 574 575 576 577 578 579 580 582 583 584 585 586 587 588 589 590 591 592 593 594 595 596 597 598 599 600 601 602 603 604 605 606 607 608 609 610 611 613 614 617 618 619 620 621 622 623 624 626 627 628 629 632 633 635 636 638 639 642 643 644 645 646 648 649 650 652 653 654 655 656 657 658 659 660 661 662 663 664 665 667 668 669 670 671 673 674 676 677 678 679 680 681 682 684 686 687 688 689 691 692 693 695 696 698 699 700 701 702 703 704 705 706 707 708 709 710 711 712 714 715 717 718 719 720 721 722 723 724 725 726 727 728 730 731 732 733 734 735 736 737 738 739 740 741 742 743 744 745 746 748 749 750 752 753 756 758 759 760 761 762 763 764 765 766 767 768 770 771 772 773 774 775 776 777 779 781 782 783 784 785 786 787 788 789 790 791 792 793 795 797 799 800 801 803 804 805 806 807 808 809 810 812 813 814 815 816 817 818 819 820 821 822 823 826 827 828 829 830 831 832 833 834 836 837 838 839 840 842 844 845 846 847 848 849 850 851 852 853 854 856 857 858 859 860 861 863 864 865 867 868 869 870 872 873 874 876 877 878 880 881 882 883 884 885 886 887 888 889 892 893 894 895 896 897 898 899 900 901 902 903 904 905 906 908 909 910 911 912 914 915 916 917 918 919 922 923 924 925 926 927 930 931 932 933 934 935 936 937 938 939 941 942 943 944 945 947 948 949 950 952 953 954 956 957 958 959 960 961 962 963 965 967 968 969 971 972 973 974 975 976 977 978 979 980 981 982 985 987 989 990 991 992 993 994 995 996 997 998 999 1000 798 879 1 5 16 34 38 47 63 79 80 89 96 99 103 128 130 138 140 141 142 150 162 172 173 178 185 190 193 201 206 209 214 224 228 239 244 255 257 260 261 264 266 268 275 278 283 289 292 299 305 309 325 326 328 330 345 347 361 363 364 372 380 395 398 401 402 409 410 413 418 428 429 430 432 437 442 450 456 459 485 490 503 508 511 524 534 538 540 543 545 547 548 551 556 562 572 581 612 615 616 625 630 631 634 637 640 641 647 651 666 672 675 683 685 690 694 697 713 716 729 747 751 754 755 757 769 778 780 794 796 802 811 824 825 835 841 843 855 862 866 871 875 890 891 907 913 920 921 928 929 940 946 951 955 964 966 970 983 984 986 988

12 1
879 1 

diff 13'096'377
90 623 945
мой
1 91410744 246645879
879 229201036 786799

бот
1 91410744 246645879
12 989222712 955828702
*/

    return 0;
}