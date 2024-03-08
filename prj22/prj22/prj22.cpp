﻿#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input, ' ');
    int N = stoi(input);

    getline(cin, input);
    int K = stoi(input);

    vector<int> x;

    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            getline(cin, input, ' ');
            x.push_back(stoi(input));
        }
        else
        {
            getline(cin, input);
            x.push_back(stoi(input));
        }
    }



    int res = -1;
    int min = x[0];
    int max = x[0];
    int imax = 0;
    int imin = 0;
    int il = 0;

    for (int i = 1; i < N + K - 1; i++)
    {
        if (imax <= il && i < N)
        {
            max = x[il];
            imax = il;
            for (int j = il + 1; j < i; j++)
            {
                if (max <= x[j])
                {
                    max = x[j];
                    imax = j;
                }
            }
        }
        else if (i > N - 1 && imax < i - K)
        {
            imax = N - 1;
            max = x[N - 1];
        }

        if (i < N)
            if (max <= x[i])
            {
                max = x[i];
                imax = i;
            }

        if (res < max - min && imin < imax) res = max - min;

        if (i > K - 1) il++;

        if (imin < il)
        {
            imin = il;
            min = x[il];
        }
    }


    if (res <= 0)
        cout << "0" << endl;
    else
        cout << res << endl;

    /*
    11 4
    1 3 7 2 1 5 9 2 1 8 3
    8

    10 4
    10 9 8 7 6 5 4 3 2 1
    0

    10 4
    1 2 3 4 5 6 7 8 9 10

    10 4
    1 2 3 4 5 6 7 8 0 10

    2 4
    1 2

    2 4
    2 1

    10 0
    1 2 3 4 5 6 7 8 9 10

    2 1
    1 2

    2 1
    0 9999

    10 5
    0 0 0 0 0 0 0 0 0 0

    10 7
    9 4 9 3 8 10 9 4 5 5

    10 4
    8 10 1 9 3 9 10 5 7 5

5000 59
181 558 440 27 511 749 393 298 854 22 655 100 269 572 397 448 696 384 939 1 677 468 451 229 873 982 365 209 153 969 538 594 117 925 811 91 732 102 185 602 753 853 520 157 244 891 22 935 521 383 737 703 3 15 492 860 43 528 955 841 545 998 254 309 293 624 65 678 102 695 387 516 166 834 804 514 819 890 408 130 993 605 304 703 333 815 248 34 837 925 952 880 382 998 585 901 854 531 949 833 908 826 755 366 163 16 724 237 932 541 465 544 495 730 491 611 949 204 264 186 567 364 634 527 705 122 677 822 237 110 343 484 676 505 618 721 203 439 460 250 997 382 669 755 987 686 373 97 155 621 529 514 524 366 946 412 77 399 756 71 404 703 345 59 949 244 852 356 14 936 794 16 403 371 332 404 996 516 444 948 598 628 865 417 857 736 29 21 268 9 569 510 118 121 884 66 942 645 88 606 410 895 773 931 517 544 628 606 90 748 606 158 316 819 152 399 319 222 953 150 935 823 384 938 921 34 179 878 242 681 519 55 777 759 129 344 800 469 963 732 357 360 121 317 557 263 383 522 53 146 455 166 791 413 678 708 680 552 192 578 475 825 369 10 894 105 286 757 26 827 607 551 624 442 270 868 341 761 889 989 308 397 128 861 711 216 473 240 842 378 879 280 171 926 66 681 546 175 389 263 92 718 563 717 731 384 653 426 560 843 643 18 985 168 392 441 769 225 993 149 382 728 768 756 465 885 464 270 422 78 314 852 919 767 669 260 423 309 821 221 330 795 48 166 152 113 808 340 599 620 282 950 702 996 749 756 201 287 888 167 108 408 616 835 718 874 641 728 111 244 758 720 335 214 465 477 492 312 58 802 12 125 342 151 559 959 870 366 928 255 852 235 296 705 48 653 101 542 854 214 581 445 82 921 425 722 863 892 120 413 430 85 774 331 837 947 314 319 504 703 631 396 569 341 297 450 139 895 988 393 298 395 93 951 926 415 887 234 493 417 788 679 936 587 224 360 305 249 786 201 352 916 535 177 969 974 735 116 565 602 526 208 454 975 284 496 307 257 163 140 517 446 898 817 891 586 484 671 347 699 919 544 304 98 838 662 819 587 598 4 850 690 922 905 586 469 12 27 45 259 140 149 20 568 455 721 697 752 889 157 69 201 873 962 675 600 246 223 177 672 135 405 994 237 294 47 391 960 9 411 5 307 153 563 101 537 863 988 374 399 438 447 252 813 209 202 799 796 812 615 572 272 540 224 845 304 773 459 813 434 991 853 11 254 187 676 470 112 878 982 255 502 764 104 214 975 522 949 266 667 330 881 662 383 55 498 87 626 101 163 770 317 655 370 720 466 531 493 874 279 796 851 547 373 424 186 502 143 895 957 214 427 931 5 890 219 936 639 371 96 205 29 776 865 28 218 675 379 641 423 84 224 321 840 388 863 751 126 388 873 149 739 512 642 757 530 280 751 403 480 919 713 176 399 690 386 713 841 824 174 688 665 388 947 188 234 561 43 406 226 159 524 296 33 786 807 996 782 656 655 272 605 870 285 272 477 64 402 335 75 805 785 74 234 559 623 618 362 415 468 26 335 456 582 29 33 331 386 637 640 804 299 398 830 479 661 970 763 921 307 79 190 963 798 879 63 984 149 1 635 54 242 725 276 955 745 524 378 111 295 249 610 1000 70 484 575 307 473 457 699 373 82 624 764 953 725 309 1000 823 17 256 725 664 210 505 607 183 776 599 873 107 83 99 432 133 903 27 640 939 733 394 883 644 398 816 202 49 526 346 314 183 775 16 785 554 356 240 664 771 27 527 150 202 623 391 597 343 843 931 515 790 29 413 525 141 7 265 664 96 116 561 986 278 305 680 417 896 885 231 205 571 937 3 138 118 892 151 940 342 557 182 404 700 101 801 215 997 323 475 974 798 130 71 103 871 581 416 438 74 143 91 22 781 425 935 208 860 101 219 599 79 561 445 795 619 912 674 403 802 709 964 938 897 157 552 265 231 498 4 976 516 802 232 596 916 765 359 310 153 273 398 952 293 190 386 685 795 758 565 197 195 309 574 231 541 115 710 142 383 916 344 239 167 400 534 312 65 292 342 705 769 843 141 310 401 646 793 64 687 756 497 431 85 567 118 366 268 216 709 241 177 869 752 920 304 225 716 1 434 38 260 175 141 695 465 831 928 91 628 151 520 297 385 334 469 679 735 419 539 353 340 247 348 353 899 583 628 863 753 297 528 991 166 310 605 868 288 175 87 349 466 474 475 100 697 901 589 680 501 50 289 474 322 267 712 974 475 165 604 519 48 342 426 984 405 766 232 939 288 936 545 836 314 166 960 862 78 676 377 38 590 861 433 591 576 87 271 885 717 338 200 277 282 791 481 732 706 902 722 112 761 8 344 586 562 418 608 157 411 890 610 584 402 136 8 842 661 305 934 929 909 289 445 358 818 306 792 941 577 817 60 761 117 142 985 379 42 992 40 414 261 255 75 540 526 107 688 665 991 809 430 507 659 559 570 838 206 477 547 600 840 785 164 563 763 726 979 287 796 542 114 749 7 605 115 45 553 921 994 404 512 351 947 718 705 333 239 132 453 870 385 686 745 160 82 748 587 568 793 893 862 142 543 514 226 486 369 176 130 471 907 422 191 631 255 721 751 95 328 660 367 630 638 789 456 606 205 685 740 229 855 828 725 681 119 619 242 453 382 921 485 431 478 722 157 860 373 813 423 803 88 800 221 953 103 653 413 265 955 681 695 638 604 25 498 830 954 466 645 284 880 549 373 993 969 754 594 473 357 724 260 45 293 414 155 595 414 36 173 780 908 699 160 405 901 583 578 336 149 142 242 56 378 111 736 394 140 771 293 59 347 808 523 598 865 742 454 197 212 758 40 211 342 507 666 266 691 766 110 258 14 642 597 500 618 166 398 106 731 930 742 398 460 724 399 223 20 174 267 924 195 104 451 261 384 660 33 669 223 78 74 400 828 692 802 390 904 719 851 804 207 311 279 483 6 186 340 921 218 855 443 661 703 417 678 402 417 956 145 975 577 841 285 16 741 880 753 185 33 969 250 334 718 777 941 445 757 101 166 532 596 30 918 209 389 3 867 807 393 109 675 760 632 292 951 26 126 228 546 91 448 339 4 46 642 978 314 277 663 313 581 454 954 520 355 122 849 404 610 850 323 558 293 166 465 102 293 821 617 72 696 163 372 296 208 457 528 381 205 673 844 642 146 441 424 846 655 705 612 259 609 211 172 512 824 155 551 950 629 6 810 574 95 901 418 980 665 858 197 959 360 526 244 832 512 267 291 577 408 95 952 855 885 323 29 120 507 482 189 152 123 294 711 728 895 968 502 726 961 194 679 937 280 530 454 560 879 981 165 712 428 442 209 151 371 898 555 827 377 382 760 542 516 642 644 383 898 454 518 627 735 460 319 18 754 25 307 357 506 712 637 977 639 58 346 315 820 254 874 551 102 883 968 678 399 4 666 23 123 666 250 944 161 860 5 172 208 640 366 214 475 903 584 45 877 888 691 982 53 30 602 980 613 406 301 240 634 903 220 270 848 399 762 323 838 956 919 919 847 367 463 184 233 330 448 212 116 822 980 895 233 202 828 981 287 355 55 466 262 607 13 478 603 20 463 362 276 600 40 647 768 651 139 918 514 20 7 595 24 550 523 791 776 560 474 991 850 587 579 340 100 542 642 984 532 236 520 497 877 226 918 529 952 688 872 665 348 812 584 27 801 608 426 345 64 839 476 252 32 365 950 694 666 134 245 449 730 850 875 785 462 917 382 324 7 886 730 574 808 57 825 363 517 41 35 399 132 809 210 75 232 890 408 816 874 485 540 120 666 924 636 547 165 44 526 936 106 475 533 662 551 837 518 371 31 661 521 318 352 249 98 383 204 323 610 868 341 767 598 847 483 665 949 397 179 255 581 605 642 803 777 105 325 556 409 911 750 213 246 457 824 399 968 754 724 900 509 262 162 682 275 559 460 557 399 567 83 991 673 576 745 551 494 20 733 292 27 539 521 89 515 95 936 600 604 270 931 478 751 907 399 660 817 789 486 74 936 286 50 939 801 302 654 505 144 864 589 963 308 279 857 558 818 496 838 453 340 120 768 370 943 861 226 42 62 45 962 547 237 630 592 462 316 322 897 673 12 212 326 963 890 765 949 754 103 95 393 241 364 813 608 60 987 760 857 828 604 917 575 559 119 769 111 804 192 511 432 37 10 352 686 259 824 222 963 209 707 436 865 829 145 999 629 736 6 197 187 891 105 83 472 213 523 26 171 665 306 571 59 680 893 279 231 231 477 676 123 753 840 919 211 729 993 850 506 515 271 459 818 986 662 783 374 983 818 918 228 661 86 295 856 841 48 669 984 13 451 523 90 970 837 737 44 684 672 189 412 865 567 587 831 79 297 640 674 953 753 689 447 515 841 278 34 902 707 727 906 947 973 203 365 987 241 136 345 527 488 311 78 818 37 146 158 633 940 328 465 482 465 464 386 807 221 397 242 14 138 650 18 712 678 720 87 26 153 370 394 764 260 283 491 835 901 927 515 964 490 186 200 364 196 861 873 435 947 529 728 445 390 862 378 611 555 872 258 328 522 730 590 521 543 169 109 84 875 530 490 12 632 591 949 604 442 471 652 77 455 369 551 959 199 549 368 17 275 152 530 178 659 24 796 34 612 467 270 727 595 349 85 793 334 665 492 810 712 90 391 273 167 859 474 4 427 335 572 486 670 525 797 542 822 643 367 931 56 21 926 63 887 30 989 798 357 119 767 977 677 210 169 548 990 271 464 228 112 7 944 461 757 485 336 945 816 707 127 991 286 370 488 82 358 781 926 652 818 608 751 960 597 146 164 669 913 470 723 700 614 953 840 456 386 491 331 127 621 150 101 344 672 190 977 318 843 304 65 557 188 5 121 33 278 708 666 625 374 221 576 642 151 284 987 846 502 276 50 112 859 640 254 195 146 377 627 955 72 452 179 774 226 350 339 887 211 716 273 603 146 588 381 689 394 8 484 75 812 535 757 898 627 290 925 138 741 981 705 154 247 275 10 344 463 657 810 50 496 380 784 782 17 554 919 182 270 433 936 233 725 12 259 571 89 900 342 80 685 794 324 645 922 849 746 540 98 202 207 91 716 430 360 714 698 513 390 606 337 211 975 933 472 502 980 96 423 608 86 825 600 689 284 969 542 958 757 966 512 460 790 520 785 180 932 824 567 406 842 383 382 133 107 698 912 996 686 584 489 951 544 129 534 155 668 301 903 922 579 507 615 831 309 268 12 710 397 440 281 409 284 537 812 800 443 180 991 662 409 566 502 336 937 247 689 479 859 914 575 29 858 947 302 178 546 446 514 579 190 746 584 629 866 155 976 689 645 585 861 607 780 475 488 216 844 754 282 10 751 944 156 739 783 203 253 896 14 592 865 467 193 525 62 143 59 681 874 836 76 846 167 179 703 841 824 984 16 9 505 754 20 918 735 275 882 865 182 249 697 18 491 314 523 682 935 921 208 235 938 888 13 486 229 561 71 59 940 319 428 452 11 131 914 169 662 76 193 764 462 872 91 73 234 978 746 568 709 568 75 21 7 775 427 970 125 644 748 551 311 454 684 653 711 819 933 805 74 13 117 312 553 415 646 331 45 643 925 386 716 471 949 285 453 281 171 62 112 66 858 381 186 8 319 367 505 297 791 769 51 736 604 111 555 289 211 420 843 74 238 841 808 468 844 147 210 965 859 779 10 92 857 246 252 419 965 911 121 752 160 874 141 586 103 426 214 858 544 139 943 821 358 292 720 79 617 28 755 976 77 398 592 84 495 126 56 770 723 306 900 852 405 582 237 750 310 862 65 897 986 951 674 469 448 579 800 237 728 448 10 401 793 487 236 607 393 523 856 106 847 574 900 309 764 685 269 875 687 716 641 867 993 61 116 237 829 949 762 130 548 155 33 263 2 184 288 269 446 44 281 133 207 873 173 597 604 641 381 845 961 802 75 286 817 180 211 187 257 515 605 890 708 282 590 42 764 257 697 385 977 692 953 355 211 19 33 324 565 243 11 595 10 967 939 748 255 252 755 780 790 60 37 659 654 695 65 556 276 214 651 738 604 135 871 28 273 42 369 791 824 987 7 859 311 623 1 788 131 549 663 378 848 696 11 484 639 707 906 635 943 357 358 667 843 620 945 270 946 961 304 571 528 295 172 325 883 646 458 456 157 409 326 819 881 965 36 202 510 218 584 652 720 240 139 90 771 169 484 713 413 829 669 950 952 637 882 937 946 984 215 194 120 618 909 599 802 520 678 694 582 669 945 1 266 911 791 385 143 148 581 260 438 363 457 544 174 532 780 493 271 745 849 63 615 748 109 911 493 842 179 97 146 868 51 716 619 935 613 673 148 308 48 575 689 753 756 213 994 748 531 285 428 625 433 867 616 951 681 224 307 326 841 392 568 22 844 675 476 590 952 815 572 280 573 193 225 752 925 234 220 877 945 509 60 665 403 578 672 625 942 558 150 807 178 429 451 821 601 759 453 93 143 866 584 312 541 877 709 798 865 755 963 305 955 458 370 129 488 131 266 386 276 262 442 599 725 341 170 165 136 135 774 227 783 769 654 92 233 974 268 117 644 811 109 179 695 422 748 430 856 1 914 852 494 215 968 725 444 940 279 835 567 125 462 369 187 98 149 7 725 982 607 628 886 25 137 522 882 738 906 209 489 745 458 19 963 522 843 321 605 253 69 875 922 988 678 40 52 206 852 248 60 881 977 833 220 469 749 402 871 882 791 811 936 420 228 753 652 263 905 873 864 981 474 877 537 268 807 759 849 579 554 173 348 653 147 463 472 432 715 879 893 404 281 421 802 672 746 935 538 969 926 464 455 135 605 11 639 222 65 942 614 332 8 827 519 22 917 982 340 124 120 561 801 308 243 101 79 399 170 373 622 798 619 8 555 768 927 512 713 473 304 581 574 681 647 451 396 71 584 873 813 935 417 329 563 84 183 527 966 695 794 242 38 921 796 137 1 100 562 390 613 811 279 816 740 924 7 766 260 185 720 710 786 682 217 625 668 826 680 649 377 922 686 361 414 658 837 535 580 724 940 723 197 585 140 303 260 833 137 442 973 35 611 606 30 606 163 655 107 285 422 717 957 310 998 51 923 471 638 870 590 311 631 185 124 276 191 792 2 99 415 603 806 14 777 193 70 324 851 191 186 332 213 131 659 71 717 953 376 32 9 199 521 375 744 969 185 1 558 828 724 74 185 184 653 764 114 538 957 414 640 294 974 649 934 755 822 801 559 77 820 810 741 104 49 665 214 902 366 911 718 762 35 128 744 631 461 889 115 616 443 976 529 76 24 29 207 778 347 635 601 325 687 138 455 171 115 410 543 485 976 34 714 484 367 425 956 444 366 622 895 808 425 392 760 332 577 473 885 538 917 602 322 681 727 901 508 288 520 662 223 700 999 495 919 291 206 141 2 952 874 489 470 690 744 160 395 96 334 116 201 643 146 568 298 927 534 184 439 775 666 889 586 849 149 738 119 64 578 995 209 166 668 856 714 579 326 375 792 358 43 233 719 227 477 768 75 590 395 136 731 577 169 390 655 352 656 630 896 238 908 935 900 83 334 949 484 256 30 71 972 452 662 8 724 607 228 517 122 744 878 956 640 52 821 133 553 603 24 797 324 530 27 705 622 411 118 360 468 33 297 570 208 163 857 872 237 656 599 338 531 868 481 997 610 421 440 760 474 168 786 946 401 462 935 584 847 169 76 764 821 334 806 747 949 974 132 218 955 917 561 926 152 591 537 863 923 146 58 266 661 809 976 826 658 749 418 694 409 24 412 296 644 412 701 398 928 434 855 217 624 845 306 663 123 228 85 939 918 839 744 225 780 122 780 689 447 350 301 825 731 897 946 780 240 340 804 962 7 726 168 313 179 200 31 797 96 440 948 328 585 593 798 470 42 982 900 411 219 809 712 320 705 598 897 935 187 618 894 810 467 868 537 404 679 994 307 596 975 884 157 241 413 134 715 406 863 876 586 448 824 969 605 21 45 731 628 186 426 698 350 790 217 267 650 595 615 538 910 675 72 978 531 213 824 87 294 456 225 984 351 879 835 243 173 12 522 985 814 140 132 989 194 896 669 466 71 183 961 908 169 314 427 860 276 389 214 624 63 705 782 215 650 944 837 384 304 145 394 664 780 144 425 399 535 165 305 69 650 433 818 630 971 8 606 255 696 10 454 254 39 537 823 632 652 752 913 744 803 818 426 659 347 643 519 381 194 290 412 771 967 31 9 377 153 128 498 193 391 272 108 650 661 987 279 663 493 238 295 798 1000 654 458 879 53 898 805 833 958 71 296 390 61 357 42 376 653 459 702 560 720 568 686 777 89 413 103 428 375 693 215 740 72 523 596 36 770 185 325 621 217 546 211 76 994 651 13 319 47 755 588 171 784 794 776 530 68 246 644 238 955 129 223 113 412 238 388 506 435 510 96 691 788 238 869 564 559 647 863 497 888 95 122 807 144 693 861 561 401 110 922 878 800 846 613 140 446 171 157 265 32 700 232 64 888 937 485 202 599 664 391 886 28 194 404 537 971 930 147 993 737 652 202 984 541 103 195 110 945 134 843 315 297 204 188 763 514 169 118 790 49 709 874 545 919 807 681 577 72 833 423 625 916 748 147 788 746 241 778 223 600 974 155 440 78 698 335 164 491 471 47 543 246 264 155 516 162 255 455 720 467 918 65 707 863 348 382 272 241 328 575 520 51 168 837 42 699 436 717 74 838 900 396 721 349 625 625 736 701 629 799 744 493 560 790 142 793 338 752 747 387 549 411 918 421 787 60 687 858 222 14 622 771 707 551 705 40 200 984 524 804 747 924 51 689 431 550 804 83 588 621 69 108 961 426 359 462 468 210 330 755 708 993 535 563 373 904 766 823 601 502 818 175 432 610 54 723 823 541 944 559 896 868 217 115 66 850 463 718 220 858 74 258 922 925 291 107 26 875 675 230 245 443 193 501 773 426 892 135 577 481 696 778 750 628 893 624 888 112 696 41 554 709 196 473 911 368 228 995 707 858 593 876 460 750 991 728 931 314 446 194 777 508 665 817 610 939 245 163 755 185 810 310 676 947 298 677 587 260 644 865 250 365 822 927 228 443 296 711 138 418 111 20 246 542 337 888 403 312 684 979 576 269 257 68 772 430 863 695 956 254 69 767 83 855 635 887 885 3 265 92 42 457 877 736 238 285 349 864 892 138 363 893 347 149 856 124 918 628 343 494 53 950 493 469 616 612 82 636 249 263 897 970 846 508 747 997 371 842 98 460 234 111 650 722 313 989 596 909 577 185 547 804 802 592 308 181 184 904 367 111 486 361 957 654 519 930 830 390 445 495 120 430 573 266 793 317 365 171 985 12 861 838 811 935 856 298 987 716 608 302 922 137 901 272 902 8 451 962 507 101 61 349 321 925 671 155 592 651 129 824 9 171 263 743 307 563 765 161 22 213 318 744 766 854 133 29 45 140 882 869 296 433 180 177 427 23 214 868 947 639 983 648 894 892 438 507 304 345 153 753 264 737 826 62 625 684 408 774 598 931 884 18 33 985 165 568 656 301 500 967 537 481 357 535 27 25 74 733 962 283 132 549 82 508 843 215 57 458 511 540 215 608 602 651 444 585 855 88 159 747 16 759 227 604 875 306 381 605 534 155 599 372 987 889 981 307 565 923 7 658 488 243 265 190 997 541 441 39 331 337 365 879 347 373 436 884 761 754 201 800 453 265 721 745 775 510 227 736 562 226 41 200 260 308 652 471 541 642 627 895 416 465 53 263 585 58 988 499 417 928 623 39 215 797 77 360 650 701 651 553 224 215 194 652 647 95 123 314 491 601 241 990 740 273 666 716 184 94 520 809 823 646 354 531 876 977 843 162 971 46 31 889 914 816 214 431 572 660 441 114 551 242 802 186 613 778 761 151 352 26 763 88 541 288 982 924 876 875 19 608 127 253 14 113 362 461 552 153 896 763 388 832 293 992 182 948 440 714 970 963 525 163 744 117 122 530 439 696 176 971 161 331 592 867 980 988 975 196 604 969 543 496 240 110 542 934 438 993 687 137 163 850 281 768 614 903 76 540 260 289 251 649 860 155 852 45 47 523 271 265 951 89 851 830 488 895 100 620 744 359 174 21 951 425 378 969 106 787 963 302 657 40 176 836 550 629 912 988 519 540 728 614 112 732 95 7 610 196 671 530 353 702 289 921 354 744 77 353 89 357 451 703 282 719 977 758 564 752 215 131 318 767 756 951 485 584 171 651 918 64 427 488 803 709 329 515 129 534 87 348 623 475 388 577 692 227 117 523 923 388 536 421 189 517 579 29 7 569 104 775 574 900 839 514 70 145 82 592 672 379 525 448 399 348 199 77 108 823 642 927 28 180 610 385 492 110 901 365 849 180 435 558 80 855 807 368 707 292 145 196 911 340 73 610 829 702 399 395 182 113 252 888 690 608 468 240 845 133 28 223 98 601 681 562 323 561 951 208 88 851 8 950 106 969 695 600 771 799 47 654 54 756 901 803 789 724 944 331 251 361 447 721 296 422 947 818 440 325 466 898 775 893 720 902 162 939 430 845 541 346 619 979 850 998 169 1000 869 212 619 997 820 205 874 222 712 826 605 12 341 277 143 490 533 343 636 779 816 470 441 856 615 421 471 743 964 69 510 997 130 300 450 70 42 363 547 292 296 611 473 122 724 749 552 127 239 877 712 977 977 830 644 12 710 72 730 353 282 372 771 621 582 743 795 527 936 453 101 924 708 115 114 81 530 454 914 588 439 815 690 768 903 271 867 544 394 293 77 927 674 173 452 415 325 447 508 127 340 591 519 319 14 570 830 49 145 186 442 238 376 181 675 802 760 293 288 447 993 98 415 891 723 883 649 639 567 249 601 398 894 824 161 146 812 206 913 893 335 289 197 294 796 156 535 974 783 449 809 416 603 449 666 56 689 282 584 214 676 792 454 496 424 30 805 326 617 95 391 30 169 189 695 672 309 974 375 91 769 621 427 767 234 555 314 683 355 416 289 452 258 184 126 531 457 734 181 136 861 796 398 966 871 520 700 568 808 742 262 788 538 812 436 424 548 871 775 418 126 165 29 463 209 535 462 183 842 178 953 646 222 637 673 977 459 299 484 737 763 9 247 411 887 486 272 653 645 35 215 255 241 675 225 299 286 267 865 210 975 707 551 995 740 613 809

    */

    return 0;
}