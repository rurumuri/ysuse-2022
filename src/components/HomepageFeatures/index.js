import clsx from 'clsx';
import Heading from '@theme/Heading';
import Link from '@docusaurus/Link';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: '燕山大学软件工程专业不登校指南',
    link: 'docs/intro',
    linktext: '燕山大学，启动！',
    description: (
      <>
        受{' '}
        <Link to="https://github.com/npu-cs/Course-Material">
          西工大计算机专业课程攻略
        </Link>
        、{' '}
        <Link to="https://csdiy.wiki/">csdiy</Link>{' '}
        等相关项目启发的燕山大学软件工程专业不登校指南，
        <br />
        包含燕山大学信息科学与工程学院软件工程专业相关资料。目前资料和信息均以 2022 级课程为基础，部分内容可能具有时效性。
      </>
    ),
  },
];

function Feature({title, link, linktext, description}) {
  return (
    <div className={clsx('col')}>
      <div className="text--center padding-horiz--md">
        <Heading as="h3">{title}</Heading>
        <p>{description}</p>
        <div className={styles.buttons}>
          <Link
            className="button button--secondary button--lg"
            to={link}>
            {linktext}
          </Link>
        </div>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
