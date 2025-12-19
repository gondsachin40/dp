
Monday, December 30, 2024
3:18 PM

Buying apples
https://www.spoj.com/problems/ABA12C/

Alpha code
https://www.spoj.com/problems/ACODE/

Tri Tiling
http://poj.org/problem?id=2663

New Year and the Permutation Concatentation
https://codeforces.com/problemset/problem/1091/D

Multiplicity
https://codeforces.com/problemset/problem/1061/C

Consecutive Subsequence
https://codeforces.com/problemset/problem/977/F

Animals
https://codeforces.com/problemset/problem/35/D

Soldier and Number Game
https://codeforces.com/problemset/problem/546/D

Robber's watch
https://codeforces.com/problemset/problem/685/A





%-------------------------
% Resume in Latex
% Author : Adapted for Sachin Gond
% Based off of: https://github.com/sb2nov/resume
% License : MIT
%------------------------

\documentclass[letterpaper,11pt]{article}

\usepackage{latexsym}
\usepackage[empty]{fullpage}
\usepackage{titlesec}
\usepackage{marvosym}
\usepackage[usenames,dvipsnames]{color}
\usepackage{verbatim}
\usepackage{enumitem}
\usepackage[hidelinks]{hyperref}
\usepackage{fancyhdr}
\usepackage[english]{babel}
\usepackage{tabularx}
\usepackage{fontawesome5}
\usepackage{multicol}
\setlength{\multicolsep}{-3.0pt}
\setlength{\columnsep}{-1pt}
\input{glyphtounicode}
\definecolor{airforceblue}{rgb}{0.36, 0.54, 0.66}

\pagestyle{fancy}
\fancyhf{} % clear all header and footer fields
\fancyfoot{}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% Adjust margins
\addtolength{\oddsidemargin}{-0.6in}
\addtolength{\evensidemargin}{-0.5in}
\addtolength{\textwidth}{1.19in}
\addtolength{\topmargin}{-.7in}
\addtolength{\textheight}{1.4in}

\urlstyle{same}
\raggedbottom
\raggedright
\setlength{\tabcolsep}{0in}

% Sections formatting
\titleformat{\section}{
  \vspace{-4pt}\scshape\raggedright\large\bfseries
}{}{0em}{}[\color{black}\titlerule \vspace{-5pt}]

% Ensure that generated pdf is machine readable/ATS parsable
\pdfgentounicode=1

%-------------------------
% Custom commands
\newcommand{\resumeItem}[1]{
  \item\small{
    {#1 \vspace{-2pt}}
  }
}

\newcommand{\resumeSubheading}[4]{
  \vspace{-2pt}\item
    \begin{tabular*}{1.0\textwidth}[t]{l@{\extracolsep{\fill}}r}
      \textbf{#1} & \textbf{\small #2} \\
      \textit{\small#3} & \textit{\small #4} \\
    \end{tabular*}\vspace{-7pt}
}

\newcommand{\resumeItemListStart}{\begin{itemize}}
\newcommand{\resumeItemListEnd}{\end{itemize}\vspace{-5pt}}
\newcommand{\resumeSubHeadingListStart}{\begin{itemize}[leftmargin=0.0in, label={}]}
\newcommand{\resumeSubHeadingListEnd}{\end{itemize}}

% Make external-link icon appear with \href text
\let\orighref\href
\renewcommand{\href}[2]{\orighref{#1}{#2\,\faExternalLink}}

%-------------------------------------------
%%%%%%  RESUME STARTS HERE  %%%%%%%%%%%%%%%%%%%%%%%%%%%%

\begin{document}

%----------HEADING----------
\begin{center}
    {\Huge \scshape Sachin Gond} \\ \vspace{1pt}
    \small 
    \raisebox{-0.1\height}\faPhone\ +91 9691960299 ~
    \faEnvelope\  {gondsachin2006@gmail.com} ~
    \href{https://www.linkedin.com/in/sachin-gond-0a1607324/}{\raisebox{-0.2\height}\faLinkedin\ \underline{sachin-gond}} ~
    \href{https://github.com/gondsachin40}{\raisebox{-0.2\height}\faGithub\ \underline{gondsachin40}} ~
    \href{https://leetcode.com/u/gondsachin40/}{\raisebox{-0.2\height}\faCode\ \underline{Leetcode}}
\end{center}
%-----------TECHNICAL SKILLS-----------
\section{Technical Skills}
 \begin{itemize}[leftmargin=0.15in, label={}]
    \small{
    \item{
    
     \textbf{Languages:} JavaScript, Java, Python, C++, TypeScript\\
     \textbf{Frameworks \& Libraries:} AngularJS, Spring Boot, ReactJS, Express.js, Flask, Bootstrap \\
     \textbf{Databases:} MySQL, MongoDB, Redis\\
     \textbf{Tools:} Git/Github , Postman , IntelliJ Idea\\
     }}
 \end{itemize}
 
%-----------EXPERIENCE-----------
\section{Experience}
\resumeSubHeadingListStart
  \resumeSubheading
    {Exam Traning Portal}{Oct 2025 -- Present}\\
    \textbf{}
    \vspace{-20pt}
   \resumeItemListStart
   \resumeItem{\textbf{System Design \& Development –} Designed and implemented a full-stack internal portal using \textbf{React (SPA)} and \textbf{Flask}, creating \textbf{50+ RESTful APIs} to manage users, exams, courses, and evaluation workflows.}

    \resumeItem{\textbf{User Management \& Access Control –} Implemented authentication, role-based access control, team/project management, course uploads, and training progress tracking.}
    \resumeItem{\textbf{Exam System –} Built auto-graded objective questions and manual evaluation workflow for descriptive answers with evaluator assignment and notifications.}
    \resumeItem{\textbf{Database \& Caching –} Integrated database interactions using \textbf{SQLAlchemy} and optimized session management with \textbf{Redis}.}
    \resumeItem{\textbf{MVP Delivery –} Delivered a secure, production-ready portal enabling smooth onboarding, exam management, and training tracking.}
  \resumeItemListEnd

\resumeSubHeadingListEnd


\section{Projects}
  \resumeSubHeadingListStart
   \hspace{-25pt} % <--- Moves the title to the left
    \resumeProjectHeading
      {\textbf{Educational Web Application}
    \vspace{-20pt}

\resumeItemListStart
    \resumeItem{\textbf{Technologies:} \textbf{React}, \textbf{Node.js/Express.js}, \textbf{MongoDB}, \textbf{Ollama}}
    \resumeItem{Built a full-stack educational website to help users learn, test, and generate content on various topics.}
    \resumeItem{Implemented features to read curated content, generate quizzes, create PDFs, ask AI questions, and generate study articles.}
    \resumeItem{Designed the application with responsive UI and smooth user interactions for better learning experience.}
\resumeItemListEnd

  
 \resumeProjectHeading 
    {\textbf{2D Platformer Game} $|$ \emph{\href{https://gondsachin40.github.io/GAME-2d/}{Live-link}}}
\vspace{-10pt}

    \resumeItemListStart
    \resumeItem{\textbf{Technologies:} \textbf{JavaScript}, \textbf{HTML\&Canvas}}
    \resumeItem{Developed a side-scrolling 2D platformer game using \textbf{JavaScript} and \textbf{HTML Canvas}.}
    \resumeItem{Implemented \textbf{OOP} concepts, collision detection, sprite sheet animations, and multiple game stages.}
    \resumeItem{Added background music and unique superpower mechanics for enhanced gameplay experience.}
    \resumeItem{Created smooth side-scrolling and interactive features to engage players.}
    
\resumeItemListEnd
\resumeProjectHeading
    {\textbf{Chess} \hfill June 2024}
\vspace{-10pt}

    \resumeItemListStart
    \resumeItem{\textbf{Technologies:} \textbf{JavaScript}, \textbf{HTML Canvas}, \textbf{Socket.IO}}
    \resumeItem{Developed a chess game supporting two-player mode on a single device and two-player mode across devices using \textbf{Socket.IO}.}
    \resumeItem{Used \textbf{HTML Canvas} for board rendering and implemented complex move validation and game logic using \textbf{Depth-First Search (DFS)} algorithms.}
    \resumeItem{Ensured synchronized game state over the network for smooth, real-time gameplay experience.}
\resumeItemListEnd
    
\resumeItemListEnd


  \resumeSubHeadingListEnd
% <--- Don't forget to close it
% \resumeSubHeadingListStart
% \resumeItemListStart
% \resumeSubHeadingListStart
% \resumeSubHeadingListEnd
% \resumeSubheading
%     {2D Platformer Game}
% % \resumeItemListStart
% %     \resumeItem{\textbf{Technologies:} JavaScript, HTML\&Canvas}
% %     \resumeItem{Developed a side-scrolling 2D platformer game using JavaScript and HTML Canvas.}
% %     \resumeItem{Implemented OOP concepts, collision detection, sprite sheet animations, and multiple game stages.}
% %     \resumeItem{Added background music and unique superpower mechanics for enhanced gameplay experience.}
% %     \resumeItem{Created smooth side-scrolling and interactive features to engage players.}
% % \resumeItemListEnd

% \resumeSubHeadingListEnd


%-----------ACHIEVEMENTS-----------
\section{Achievements}
\resumeItemListStart
 \resumeItem{\textbf{Specialist} on \href{https://www.codeforces.com/profile/gondsachin40}{\textbf{\underline{Codeforces}}}}\vspace{-5pt}
 
    \resumeItem{Secured \textbf{48th rank} in \textbf{CodeChef Starters 178C}; 4-star rated on \href{https://www.codechef.com/users/gondsachin40}{\textbf{\underline{CodeChef}}}}\vspace{-5pt}
    \resumeItem{Ranked \textbf{222nd} in \textbf{GeeksforGeeks Weekly Contest 190.}}\vspace{-5pt}
    \resumeItem{Ranked Top \textbf{4.5\% Global} (\textbf{Knight}) on  \href{https://leetcode.com/u/gondsachin40/}{\textbf{\underline{LeetCode}}}; Peak Rating: \textbf{1890}}\vspace{-5pt}
    \resumeItem{Naukri.com Weekly Contest 207: Secured \textbf{12th rank AIR.}}
\resumeItemListEnd

%-----------EDUCATION----------- 
\section{Education}
\resumeSubHeadingListStart
\resumeSubheading
  {Lakshmi Narain College Of Technology \& Science}{June 2023 - June 2027}
  {\textbf{\textnormal{BTech in Computer Science \& Engineering}}}{\textnormal{Bhopal, MP}}
\resumeSubHeadingListEnd


\end{document}
